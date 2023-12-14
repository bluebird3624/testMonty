#include "monty.h"

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    stack_t *stack = NULL;
    char opcode[128];
    int value;
    unsigned int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }



    while (fscanf(file, "%127s", opcode) != EOF)
    {
        line_number++;
        if (strcmp(opcode, "push") == 0)
        {
            if (fscanf(file, "%d", &value) == 1)
                push(&stack, value);
            else
            {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }
        }
        else if (strcmp(opcode, "pall") == 0)
        {
            pall(&stack, line_number);
        }
        
        else
        {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
	

    return EXIT_SUCCESS;
}

