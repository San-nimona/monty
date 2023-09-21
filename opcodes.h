#ifndef OPCODES_H
#define OPCODES_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - Doubly linked list representation of a stack (or queue).
 * @n: Integer value stored in the node.
 * @prev: Pointer to the previous element of the stack (or queue).
 * @next: Pointer to the next element of the stack (or queue).
 *
 * Description: Structure representing a doubly linked list node for stack, queue,
 *              LIFO, FIFO in the Holberton project.
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct stack_s - Doubly linked list representation of a stack (or queue).
 * @n: Integer value stored in the node.
 * @prev: Pointer to the previous element of the stack (or queue).
 * @next: Pointer to the next element of the stack (or queue).
 *
 * Description: Structure representing a doubly linked list node for stack, queue,
 *              LIFO, FIFO in the Holberton project.
 */


typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;


/**
 * struct instruction_s - Opcode and its corresponding function.
 * @opcode: The opcode.
 * @f: Function to handle the opcode.
 *
 * Description: Structure representing an opcode and its corresponding function
 *              for the stack, queue, LIFO, and FIFO operations in the Holberton project.
 */


typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void f_push(stack_t **head, unsigned int number);
void f_pall(stack_t **head, unsigned int number);
void f_pint(stack_t **head, unsigned int number);
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);
void free_stack(stack_t *head);
void f_pop(stack_t **head, unsigned int counter);
void f_swap(stack_t **head, unsigned int counter);
void f_add(stack_t **head, unsigned int counter);
void f_nop(stack_t **head, unsigned int counter);
void f_sub(stack_t **head, unsigned int counter);
void f_div(stack_t **head, unsigned int counter);
void f_mul(stack_t **head, unsigned int counter);
void f_mod(stack_t **head, unsigned int counter);
void f_pchar(stack_t **head, unsigned int counter);
void f_pstr(stack_t **head, unsigned int counter);
void f_rotl(stack_t **head, unsigned int counter);
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void f_queue(stack_t **head, unsigned int counter);
void f_stack(stack_t **head, unsigned int counter);
#endif
