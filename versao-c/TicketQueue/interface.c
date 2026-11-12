#define UNICODE
#define _UNICODE
#include <windows.h>
#include <wchar.h>
#include <wctype.h>
#include <string.h>
#include "fila.h"
#include "interface.h"
#define ID_ENTRAR 101
#define ID_CHAMAR 102
#define ID_COMPRAR 103
#define INGRESSOS_INICIAIS 10
static Fila fila;
static Usuario atual;
static int em_atendimento=0, ingressos=INGRESSOS_INICIAIS;
static HWND campo, lista, rotulo_ingressos, rotulo_atual, status, entrar, chamar, comprar;
static HFONT fonte;
static HWND controle(HWND pai,const wchar_t *classe,const wchar_t *titulo,DWORD estilo,int x,int y,int w,int h,int id){
 HWND c=CreateWindowExW(0,classe,titulo,WS_CHILD|WS_VISIBLE|estilo,x,y,w,h,pai,(HMENU)(INT_PTR)id,GetModuleHandleW(NULL),NULL);
 SendMessageW(c,WM_SETFONT,(WPARAM)fonte,TRUE);return c;
}
static void para_unicode(const char *s,wchar_t *dest,int n){
 if(!MultiByteToWideChar(CP_UTF8,0,s,-1,dest,n)) dest[0]=L'\0';
}
static void aviso(const wchar_t *s){SetWindowTextW(status,s);}
static void atualizar(void){
 wchar_t buf[220],nome[TAM_NOME];Usuario u;
 swprintf(buf,220,L"Ingressos disponiveis: %d",ingressos);SetWindowTextW(rotulo_ingressos,buf);
 SendMessageW(lista,LB_RESETCONTENT,0,0);
 for(int i=0;i<fila.quantidade;i++){
  if(mostrar_fila(&fila,i,&u)){
   para_unicode(u.nome,nome,TAM_NOME);
   swprintf(buf,220,L"%d - %ls",i+1,nome);
   SendMessageW(lista,LB_ADDSTRING,0,(LPARAM)buf);
  }
 }
 if(em_atendimento){para_unicode(atual.nome,nome,TAM_NOME);swprintf(buf,220,L"Em atendimento: %ls",nome);}
 else wcscpy(buf,L"Em atendimento: ninguem");
 SetWindowTextW(rotulo_atual,buf);
 EnableWindow(entrar,ingressos>0&&!fila_cheia(&fila));
 EnableWindow(chamar,ingressos>0&&!em_atendimento&&!fila_vazia(&fila));
 EnableWindow(comprar,ingressos>0&&em_atendimento);
}
static void entrar_na_fila(void){
 wchar_t nome[TAM_NOME],mensagem[220];char utf8[TAM_NOME*4];
 if(ingressos==0){aviso(L"Ingressos esgotados!");return;}
 if(fila_cheia(&fila)){aviso(L"A fila esta cheia!");return;}
 GetWindowTextW(campo,nome,TAM_NOME);
 int inicio=0;while(iswspace(nome[inicio]))inicio++;
 int fim=(int)wcslen(nome);while(fim>inicio&&iswspace(nome[fim-1]))fim--;
 nome[fim]=L'\0';
 if(fim==inicio){aviso(L"Digite um nome valido.");return;}
 if(!WideCharToMultiByte(CP_UTF8,0,nome+inicio,-1,utf8,sizeof(utf8),NULL,NULL)){
  aviso(L"Erro ao ler nome.");return;
 }
 if(enfileirar(&fila,utf8)){
  swprintf(mensagem,220,L"Usuario adicionado! Posicao: %d",fila.quantidade);
  aviso(mensagem);SetWindowTextW(campo,L"");
 }else aviso(L"Nao foi possivel entrar na fila.");
 atualizar();
}
static void chamar_proximo(void){
 wchar_t nome[TAM_NOME],mensagem[220];
 if(ingressos==0){aviso(L"Ingressos esgotados!");return;}
 if(em_atendimento){aviso(L"Finalize a compra atual.");return;}
 if(!desenfileirar(&fila,&atual)){aviso(L"A fila esta vazia!");return;}
 em_atendimento=1;para_unicode(atual.nome,nome,TAM_NOME);
 swprintf(mensagem,220,L"%ls foi chamado para comprar!",nome);
 aviso(mensagem);atualizar();
}
static void confirmar(void){
 wchar_t nome[TAM_NOME],mensagem[220];
 if(!em_atendimento){aviso(L"Nenhum usuario em atendimento.");return;}
 if(ingressos==0){aviso(L"Ingressos esgotados!");return;}
 para_unicode(atual.nome,nome,TAM_NOME);ingressos--;em_atendimento=0;
 swprintf(mensagem,220,L"Compra confirmada para %ls!",nome);
 aviso(ingressos==0?L"Ingressos esgotados!":mensagem);atualizar();
}
static LRESULT CALLBACK janela_proc(HWND janela,UINT msg,WPARAM wp,LPARAM lp){
 (void)lp;
 switch(msg){
 case WM_CREATE:
  fonte=CreateFontW(18,0,0,0,FW_NORMAL,FALSE,FALSE,FALSE,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,CLEARTYPE_QUALITY,DEFAULT_PITCH,L"Segoe UI");
  inicializar_fila(&fila);
  controle(janela,L"STATIC",L"TICKETQUEUE",SS_CENTER,20,15,540,35,0);
  controle(janela,L"STATIC",L"Festival Conexao | Sao Paulo | 20/12/2026",SS_CENTER,20,55,540,30,0);
  rotulo_ingressos=controle(janela,L"STATIC",L"",SS_CENTER,20,90,540,30,0);
  controle(janela,L"STATIC",L"Nome do usuario:",0,25,140,200,25,0);
  campo=controle(janela,L"EDIT",L"",WS_BORDER|ES_AUTOHSCROLL,25,170,320,32,104);
  entrar=controle(janela,L"BUTTON",L"Entrar na fila",BS_PUSHBUTTON,355,170,195,32,ID_ENTRAR);
  controle(janela,L"STATIC",L"Usuarios aguardando:",0,25,220,300,25,0);
  lista=controle(janela,L"LISTBOX",L"",WS_BORDER|WS_VSCROLL|LBS_NOTIFY|LBS_NOINTEGRALHEIGHT,25,250,525,170,105);
  rotulo_atual=controle(janela,L"STATIC",L"",0,25,435,525,30,0);
  chamar=controle(janela,L"BUTTON",L"Chamar proximo",BS_PUSHBUTTON,25,475,250,38,ID_CHAMAR);
  comprar=controle(janela,L"BUTTON",L"Confirmar compra",BS_PUSHBUTTON,290,475,260,38,ID_COMPRAR);
  status=controle(janela,L"STATIC",L"Sistema iniciado. Aguardando usuarios.",SS_CENTER,25,530,525,45,0);
  atualizar();return 0;
 case WM_COMMAND:
  switch(LOWORD(wp)){
   case ID_ENTRAR:entrar_na_fila();break;
   case ID_CHAMAR:chamar_proximo();break;
   case ID_COMPRAR:confirmar();break;
  }return 0;
 case WM_DESTROY:DeleteObject(fonte);PostQuitMessage(0);return 0;
 }
 return DefWindowProcW(janela,msg,wp,lp);
}
int iniciar_interface(void){
 HINSTANCE instancia=GetModuleHandleW(NULL);
 WNDCLASSW classe={0};classe.lpfnWndProc=janela_proc;classe.hInstance=instancia;
 classe.lpszClassName=L"ClasseTicketQueue";classe.hbrBackground=(HBRUSH)(COLOR_WINDOW+1);
 classe.hCursor=LoadCursor(NULL,IDC_ARROW);
 if(!RegisterClassW(&classe)){MessageBoxW(NULL,L"Erro ao registrar janela.",L"TicketQueue",MB_ICONERROR);return 1;}
 HWND janela=CreateWindowExW(0,L"ClasseTicketQueue",L"TicketQueue - Fila Virtual",WS_OVERLAPPEDWINDOW&~WS_THICKFRAME&~WS_MAXIMIZEBOX,CW_USEDEFAULT,CW_USEDEFAULT,600,640,NULL,NULL,instancia,NULL);
 if(!janela){MessageBoxW(NULL,L"Erro ao criar janela.",L"TicketQueue",MB_ICONERROR);return 1;}
 ShowWindow(janela,SW_SHOW);UpdateWindow(janela);
 MSG mensagem;while(GetMessageW(&mensagem,NULL,0,0)>0){TranslateMessage(&mensagem);DispatchMessageW(&mensagem);}
 return (int)mensagem.wParam;
}
