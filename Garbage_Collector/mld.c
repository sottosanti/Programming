#include <stdio.h>
#include <stdlib.h>
#include "mld.h"
#include "css.h"
#include <assert.h>
#include <memory.h>

char *DATA_TYPE[] = {"UINT8", "UINT32", "INT32", "CHAR", "OBJ_PTR",
                     "VOID_PTR", "FLOAT", "DOUBLE", "OBJ_STRUCT"};

/* Dumping Function */
void 
print_structure_rec(struct_db_rec_t *struct_rec)
{
    if(!struct_rec)
        return;
    
    field_info_t *field = NULL;

    printf(ANSI_COLOR_CYAN "|------------------------------------------------------|\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "| %-20s | size = %-8d | #flds = %-3d |\n" ANSI_COLOR_RESET, struct_rec->struct_name, struct_rec->ds_size, struct_rec->n_fields);
    printf(ANSI_COLOR_CYAN "|------------------------------------------------------|------------------------------------------------------------------------------------------|\n" ANSI_COLOR_RESET);

    for(int j = 0; j < struct_rec->n_fields; j++) {
        field = &struct_rec->fields[j];

        printf("  %-20s |", "");
        printf("%-3d %-20s | dtype = %-15s | size = %-5d | offset = %-6d|  nstructname = %-20s  |\n",
                j, field->fname, DATA_TYPE[field->dtype], field->size, field->offset, field->nested_str_name);
        printf("  %-20s |", "");
        printf(ANSI_COLOR_CYAN "--------------------------------------------------------------------------------------------------------------------------|\n" ANSI_COLOR_RESET);
    }
}