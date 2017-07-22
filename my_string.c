#include <stdlib.h>
#include <stdio.h>
#include "my_string.h"
#include <ctype.h>

struct my_string
{
    char *data;
    int size;
    int capacity;
};
typedef struct my_string My_string;

struct node;
typedef struct node Node;

struct node
{
	Node* left;
	Node* right;
	GENERIC_VECTOR word_list;
	MY_STRING key_family;
	//int key;
	int balance_factor;
};


struct generic_vector
{
	int size;
	int capacity;
	Item* data;
	Status (*item_assign)(Item*, Item);
	void (*item_destroy)(Item*);
};

typedef struct generic_vector Generic_vector;

MY_STRING my_string_init_default(void)
{
    My_string *pMy_string;

    pMy_string = (My_string*) malloc(sizeof(My_string));

    if(pMy_string != NULL)
    {
        pMy_string->size = 0;
        pMy_string->capacity = 7;
        pMy_string ->data = (char*) malloc(sizeof(char*) * pMy_string->capacity);

        if(pMy_string->data == NULL)
        {
            printf("could not allocate memory for character array\n");
	    free(pMy_string);
            exit(1);
        }
    }

    return pMy_string;
}

MY_STRING my_string_init_c_string(const char* c_string)
{
    int i;
    int count = 0;
    while (c_string[count] != '\0')
    {
        count++;
    }
    My_string *pMy_string = (My_string*) malloc(sizeof(My_string));


    if(pMy_string != NULL)
    {
        pMy_string->size = count;
        pMy_string->capacity = count + 1;
        pMy_string ->data = (char*) malloc(sizeof(char) * pMy_string->capacity);

        if(pMy_string ->data == NULL)
        {
            printf("could not allocate memory for character array\n");
            exit(1);
        }
        for(i = 0; i < pMy_string->size; i++)
        {
            pMy_string->data[i] = c_string[i];

        }
    }

    if(pMy_string == NULL)
    {
        free(pMy_string);
        pMy_string = NULL;
    }

    return pMy_string;
}

int my_string_get_capacity(MY_STRING hMy_string)
{
    My_string *pMy_string = (My_string*) hMy_string;
    return pMy_string->capacity;
}

int my_string_get_size(MY_STRING hMy_string)
{
    My_string *pMy_string = (My_string*) hMy_string;
    return pMy_string->size;
}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string)
{
    int i;
    My_string *Left_string = (My_string*) hLeft_string;
    My_string *Right_string = (My_string*) hRight_string;

    if(Left_string->size < Right_string->size)
    {
        return -5;
    }

    else if(Left_string->size > Right_string->size)
    {
        return 5;
    }

    for(i = 0; i <= Left_string->size ; i++)
    {
        if(Left_string->data[i] < Right_string->data[i])
        {
            return -5;
        }
        else if(Left_string->data[i] > Right_string->data[i])
        {
            return 5;
        }
    }


    return 0;
}

Status my_string_extraction(MY_STRING hMy_string, FILE* fp)
{
    My_string *pMy_string = (My_string*) hMy_string;
    char *temp;
    char ch;
    int ret;
    int i;

    pMy_string->size = 0;

    ret = fscanf(fp, " %c", &ch);
    if (ret == EOF)
    {
        return FAILURE;
    }

    while(ret != EOF && !isspace(ch))
    {
        pMy_string->data[pMy_string->size] = ch;
        pMy_string->size++;
        ret = fscanf(fp, "%c", &ch);

        if(pMy_string->size >= pMy_string->capacity)
        {
            temp = (char*) malloc(sizeof(char) * pMy_string->capacity * 2);
            pMy_string->capacity *= 2;

            if (temp == NULL)
            {
                printf("could not allocate memory for resize");
                exit(1);
            }

                for (i = 0; i < pMy_string->size; i++)
                {
                    temp[i] = pMy_string->data[i];
                }

            free(pMy_string->data);
            pMy_string->data = temp;

        }
    }
    if (ret != EOF)
   {
	ungetc(ch ,fp);
   }

    return SUCCESS;
}

Status my_string_insertion(MY_STRING hMy_string, FILE* fp)
{
    My_string *pMy_string = (My_string*) hMy_string;
    int i;

    if (pMy_string->size == 0)
    {
        return FAILURE;
    }

    for (i = 0; i < pMy_string->size; i++)
    {
        fprintf(fp, "%c", pMy_string->data[i]);
    }
    printf("\n");

    return SUCCESS;
}

Status my_string_pop_back(MY_STRING hMy_string)
{
    My_string *pMy_string = (My_string*) hMy_string;

    if (pMy_string->size <=0)
    {
	return FAILURE;
    }
    pMy_string->size--;

    return SUCCESS;
}

char* my_string_at(MY_STRING hMy_string, int index)
{
    My_string *pMy_string = (My_string*) hMy_string;

    if (index < 0 || index >= pMy_string->size)
    {
	return NULL;
    }

    return pMy_string->data + index;
}

char* my_string_c_str(MY_STRING hMy_string)
{
    My_string *pMy_string = (My_string*) hMy_string;
    char* temp;
    int i;

    if (pMy_string->size >= pMy_string->capacity)
    {
	pMy_string->capacity += 2;
	temp = (char*) malloc(sizeof(char) * pMy_string->capacity);

	if(temp == NULL)
	{
	   printf("could not allocate memory for resize");
	   exit(1);
	}
	    for (i = 0; i < pMy_string->size; i++)
            {
                 temp[i] = pMy_string->data[i];
            }

    free(pMy_string->data);
    pMy_string->data = temp;
    pMy_string->data[pMy_string->capacity- 1] = '\0';
    }

    pMy_string->data[pMy_string->capacity- 1] = '\0';
    return pMy_string->data;
}

Status my_string_push_back(MY_STRING hMy_string, char item)
{
    My_string *pMy_string = (My_string*) hMy_string;
    char *temp;
    int i;

 	if(pMy_string->size >= pMy_string->capacity)
        {
            temp = (char*) malloc(sizeof(char) * pMy_string->capacity * 2);
            pMy_string->capacity *= 2;

            if (temp == NULL)
            {
                printf("could not allocate memory for resize");
                return FAILURE;
            }

                for (i = 0; i < pMy_string->size; i++)
                {
                    temp[i] = pMy_string->data[i];
                }

         free(pMy_string->data);
         pMy_string->data = temp;
         }

    pMy_string->data[pMy_string->size] = item;
    pMy_string->size++;

    return SUCCESS;
}


Status my_string_concat(MY_STRING hResult, MY_STRING hAppend)
{

    My_string *pMy_append = (My_string*) hAppend;
    int i;

    for (i = 0; i < pMy_append->size; i++)
    {
    my_string_push_back(hResult, pMy_append->data[i]);
    }

    return SUCCESS;
}

Boolean my_string_empty(MY_STRING hMy_string)
{
    My_string *pMy_string = (My_string*) hMy_string;

    if (pMy_string->size <= 0)
    {
	return TRUE;
    }

    return FALSE;
}

void my_string_destroy(Item* pItem)
{
    My_string *pMy_string = (My_string*)* pItem;
    free(pMy_string->data);
    free(pMy_string);
    *pItem = NULL;
}

Status my_string_assignment(Item* pLeft, Item Right)
{
    My_string *pMy_Right = (My_string*) Right;
    int i;

    if (*pLeft == NULL)
    {
	*pLeft = my_string_init_default();
    }

    for (i = 0; i <pMy_Right->size; i++)
    {
	my_string_push_back(*pLeft, pMy_Right->data[i]);
    }

    return SUCCESS;

}

GENERIC_VECTOR generic_vector_init_default(Status(*item_assign)(Item*, Item), void(*item_destroy)(Item*))
{
	Generic_vector* pVector;
	int i;
	pVector = (Generic_vector*)malloc(sizeof(Generic_vector));
	if (pVector != NULL)
	{

		pVector->size = 0;
		pVector->capacity = 1;
		pVector->item_destroy = item_destroy;
		pVector->item_assign = item_assign;
		pVector->data = (void**)malloc(sizeof(void*) * pVector->capacity);
		if (pVector->data == NULL)
		{

			free(pVector);
			pVector = NULL;
		}
		else
		{
			for (i = 0; i < pVector->capacity; i++)
			{
				pVector->data[i] = NULL;
			}
		}
	}
	return pVector;
}

Status generic_vector_push_back(GENERIC_VECTOR hVector, Item item)
{
	Generic_vector* pVector = (Generic_vector*)hVector;
	Item* temp;
	int i;

	if (pVector->size >= pVector->capacity)
	{
		temp = (Item*)malloc(sizeof(Item) * 2 * pVector->capacity);
		if (temp == NULL)
		{
			return FAILURE;
		}
		pVector->capacity *= 2;
		for (i = 0; i < pVector->size; i++)
		{
			temp[i] = pVector->data[i];
		}
		for (i = pVector->size; i < pVector->capacity; i++)
		{
			temp[i] = NULL;
		}
		free(pVector->data);
		pVector->data = temp;
	}

	pVector->item_assign(&pVector->data[pVector->size], item);
	pVector->size++;

	return SUCCESS;
}


int generic_vector_get_size(GENERIC_VECTOR hVector)
{
	Generic_vector* pVector = (Generic_vector*)hVector;

	return pVector->size;
}
int generic_vector_get_capacity(GENERIC_VECTOR hVector)
{
	Generic_vector* pVector = (Generic_vector*)hVector;

	return pVector->capacity;
}

Status generic_vector_pop_back(GENERIC_VECTOR hVector)
{

	Generic_vector* pVector = (Generic_vector*)hVector;
	if (pVector->size <= 0)
	{
		return FAILURE;
	}
	pVector->size--;
	return SUCCESS;
}

Item generic_vector_at(GENERIC_VECTOR hVector, int index)
{
	Generic_vector* pVector = (Generic_vector*)hVector;
	if (index < 0 || index >= pVector->size)
	{
		return NULL;
	}
	return pVector->data[index];
}

void generic_vector_destroy(GENERIC_VECTOR* phGeneric_vector)
{
	Generic_vector* pVector = (Generic_vector*)*phGeneric_vector;
	int i;

	for (i = 0; i < pVector->capacity; i++)
	{
		if (pVector->data[i] != NULL)
		{
			pVector->item_destroy(&pVector->data[i]);
		}
	}

	free(pVector->data);
	free(pVector);
	*phGeneric_vector = NULL;
}

Status get_word_key_value(MY_STRING current_word_family, MY_STRING new_key, MY_STRING word, char guess)
{
    My_string *pMy_string = (My_string*) current_word_family;
    My_string *pMy_string2 = (My_string*) word;
    My_string *pMy_string3 = (My_string*) new_key;
    pMy_string3->size = 0;
    int i;

    for (i = 0; i <my_string_get_size(word); i++)
    {
        if (pMy_string2->data[i] == guess)
        {
            if(my_string_push_back(new_key, guess) == FAILURE)
               {
                   return FAILURE;
               }
        }
        else
        {
            if(my_string_push_back(new_key, pMy_string->data[i]) == FAILURE)
               {
                   return FAILURE;
               }
        }
    }
    return SUCCESS;
}

int check_key(MY_STRING key, char guess)
{
    My_string *key_value = (My_string*) key;

    int i;

    for (i = 0; i < my_string_get_size(key_value); i++)
    {
        if (key_value->data[i] == guess)
        {
            return 1;
        }
    }

    return 0;
}




