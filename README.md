# minitalk

TODO<br/>
[] norminette in libft<br/>
[] norminette in printf<br/>
[] melhorar o makefile que não estou usando as flags, cc etc.<br/>
[] entender melhor como estou enviando 1 byte e conseguindo imprimir um caracter unicode que acredito estar fora do range de 1 byte (256 possibilidades) - contar a quantidade de bits que estou recebendo no server ao enviar um emoji, um ñ etc.<br/>
[] o que eh o formato unicode<br/>
[] entender o understand_size.c e o "como funciona??"<br/>
[] Testar colocar as declaracoes de signal dentro do while e verificar o consumo de memoria sem o pause<br/>
[] diminuir a quantidade de variáveis estáticas e no geral<br/>


If moving the msg variable from a local context (within a function) to a global context (outside any function) resolves the segmentation fault, there could be several reasons for it:

Lifetime of Variables:

Global variables persist for the entire runtime of a program.
Local variables, on the other hand, exist only for the lifetime of the function in which they're declared. Once the function returns, any memory associated with these local variables can be reclaimed, making their addresses invalid for use.
In your case, if msg was being used or modified after the function in which it was declared had already returned, it could lead to undefined behavior or a segmentation fault.

Signal Handlers:

Signal handlers have some limitations on what they can safely do.
Accessing and modifying global variables is generally safe, but there can be issues when trying to allocate memory or access local variables of other functions due to the asynchronous nature of signal handlers.
If msg was local to a function and that function had already returned by the time the signal handler tried to modify it, this could lead to a segmentation fault.

Initialization:

Global variables in C are automatically initialized to zero (for basic data types) or NULL (for pointers).
Local variables, if not explicitly initialized, contain indeterminate values.
If msg was local and not properly initialized before being used, it could lead to undefined behavior. In contrast, as a global variable, it would be automatically initialized to NULL, reducing the risk of segmentation faults due to uninitialized pointers.

Concurrency Issues:

If multiple signals are being handled concurrently, there could be race conditions that affect the behavior of the program. Global variables can sometimes be less prone to these issues if accessed atomically, but they can still be problematic without proper synchronization mechanisms.
In conclusion, while moving msg to a global context might resolve the immediate segmentation fault, it's crucial to ensure that the overall logic and flow of the program are correct. It's possible to mask other potential issues by changing variable scopes. Always ensure that variables are accessed safely, especially in the context of signal handlers.
