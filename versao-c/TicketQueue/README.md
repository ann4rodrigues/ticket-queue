# TicketQueue
Simulacao local de fila FIFO em C com interface Win32.

## Requisitos
Windows, MinGW-w64 UCRT64 (MSYS2), VS Code opcional.

## Compilar no PowerShell
```powershell
gcc main.c fila.c interface.c -o TicketQueue.exe -mwindows -luser32 -lgdi32
.\TicketQueue.exe
```

## Testar a fila (sem interface)
```powershell
gcc fila.c teste_fila.c -o teste_fila.exe
.\teste_fila.exe
```

## Arquivos
- `main.c`: inicia a interface
- `fila.h` e `fila.c`: fila circular FIFO
- `interface.h` e `interface.c`: interface Win32
- `teste_fila.c`: testes automatizados da fila
- `processo-ia.md`: modelo para registrar o processo real

A interface Windows deve ser compilada e validada no computador de destino.
