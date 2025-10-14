#include "pushswap.h"

/// Troca os dois primeiros elementos da stack
/// Se a stack tiver menos de 2 elementos, não faz nada
void	swap(node *stack)
{
	int	temp;

	if (!stack || !stack->next)   // verifica se existem pelo menos 2 nós
		return ;
	temp = stack->number;         // guarda o valor do primeiro nó
	stack->number = stack->next->number;  // primeiro recebe valor do segundo
	stack->next->number = temp;   // segundo recebe valor do primeiro
}

// Move o nó do topo de 'src' para o topo de 'dest'
// Exemplo: push(&a, &b) -> retira de B e mete em A (equivalente ao pa)
void push(node **dest, node **src)
{
    node *temp;

    if (!src || !*src)            // se src estiver vazio, não faz nada
        return;
    temp = *src;                  // guarda o primeiro nó de src
    *src = (*src)->next;          // avança o topo de src para o próximo nó
    temp->next = *dest;           // liga o nó removido à stack dest
    *dest = temp;                 // atualiza dest para apontar para o novo topo
}

/// Move o primeiro elemento da stack para o fim
/// Exemplo: [10]->[20]->[30] -> depois rotate -> [20]->[30]->[10]
void	rotate(node **stack)
{
    node	*first;
    node	*new_first;

    if (!stack || !*stack || !(*stack)->next)  // se lista vazia ou só 1 nó
        return;
    first = *stack;              // guarda o primeiro nó
    *stack = (*stack)->next;     // avança o início da stack
    first->next = NULL;          // corta a ligação do antigo primeiro
    new_first = *stack;
    while (new_first->next)      // percorre até ao último nó
        new_first = new_first->next;
    new_first->next = first;     // liga o último nó ao antigo primeiro
}

/// Move o último elemento da stack para o início
/// Exemplo: [10]->[20]->[30] -> depois reverse_rotate -> [30]->[10]->[20]
void reverse_rotate(node **stack)
{
    node	*prev;
    node	*last;

    if (!stack || !*stack || !(*stack)->next)  // se lista vazia ou só 1 nó
        return;
    prev = NULL;
    last = *stack;
    while (last->next)           // percorre até ao último nó
    {
        prev = last;             // mantém referência ao penúltimo
        last = last->next;       // avança para o próximo
    }
    prev->next = NULL;           // corta o penúltimo do último
    last->next = *stack;         // último aponta para o antigo head
    *stack = last;               // último passa a ser o novo head
}
