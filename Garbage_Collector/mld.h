#ifndef _MLD_H_
#define _MLD_H_

#include <assert.h>
#include <string.h>

// Macros
#define MAX_STRUCTURE_NAME_SIZE 128
#define MAX_FIELD_NAME_SIZE 128

// Enums
typedef enum {
    UINT8,
    UINT32,
    INT32,
    CHAR,
    OBJ_PTR,
    FLOAT,
    DOUBLE,
    OBJ_STRUCT
} data_type_t;

typedef enum {
    MLD_FALSE;
    MLD_TRUE;
} mld_boolean_t;

#define OFFSETOF(struct_name, fld_name) (unsigned long) & (((struct_name *)0)->fld_name);
#define FIELD_SIZE(struct_name, fld_name) sizeof(((struct_name *)0)->fld_name)

/* Structure Decleration */
typedef struct _struct_db_rec_ _struct_db_rec_t;

typedef struct _field_info_ {
    char fname[MAX_FIELD_NAME_SIZE];                    // Name of field
    unsigned int size;                                  // Data type of the field
    unsigned int offset;                                // Size of the field
    data_type_t dtype;                                  // Offset of the field
    char nested_str_name[MAX_STRUCTURE_NAME_SIZE];      // Meaningful if dtype = OBJ_PTR, or OBJ_STRUCT
} field_info_t;

// structure to store information of a C structure
struct _struct_db_rec_{
    _struct_db_rec_t *next;                     // Pointer to next struct
    char struct_name [MAX_STRUCTURE_NAME_SIZE]; // Key
    unsigned int ds_size;                       // Size of structure
    unsigned int n_fields;                      // Number of fields in the structure
    field_info_t *fields;                       // pointer to array of fields
};

// head of a linked list representing the structure database 
typedef struct _struct_db_ {
    struct_db_rec_t *head;
    unsigned int count;
} struct_db_t;


/* Function Prototypes */

void
print_structure_set(struct_db_rec_t *struct_rec);

void
print_structure_db(struct_db_t *struct_db);

// add a structure to the structure database
int // return 0 on success and -1 on failure
add_structure_to_struct_db(struct_db_t *struct_db, _struct_db_rec_t *struct_rec);


/* Structure Registration helping APIs */
#define FIELD_INFO(struct_name, fld_name, dtype, nested_struct_name) \
    {#fld_name, dtype, FIELD_SIZE(struct_name, fld_name),            \
        OFFSETOF(struct_name, fld_name), #nested_struct_name}

#define REG_STRUCT(struct_db, st_name, fields_arr)                   \
    do{                                                              \
        _struct_db_rec_t *rec = calloc(1, sizeof(struct_db_rec_t));  \
        strncpy(rec->struct_name, #st_name, MAX_FIELD_NAME_SIZE);    \
        rec->ds_size = sizeof(st_name);                              \
        rec->n_fields = sizeof(fields_arr)/sizeof(field_info_t);     \
        rec->fields = fields_arr;                                    \
        if(add_structure_to_struct_db(struct_db, rec)){              \
            assert(0);                                               \
        }                                                            \
    }while(0);                                                  

#endif // _MLD_H_