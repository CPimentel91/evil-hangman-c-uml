#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"
struct node;
typedef struct node Node;

struct node
{
	Node* left;
	Node* right;
	GENERIC_VECTOR word_list;
	GENERIC_VECTOR key_family;
	int balance_factor;
	int word_count;
};

void tree_insert(Node** pRoot, MY_STRING key_family, MY_STRING word);
Status my_string_push_back2(MY_STRING hMy_string, int item);
MY_STRING my_string_init_default2(void);
void preorder_traversal(Node* root);
void inorder_traversal(Node* root, int *number);
void postorder_traversal(Node* root);
void tree_destroy (Node** pRoot);
void play_hangman(GENERIC_VECTOR word_list, int guesses, int length);
void read_dictionary(void);
void clearKeyboardBuffer(void);
void get_largest_family(Node* root, int number, GENERIC_VECTOR hCopy, GENERIC_VECTOR key);
int main(int argc, char* argv[])
{
  	/*
  	MY_STRING x;
	MY_STRING y;
MY_STRING z;
	 x =  my_string_init_c_string("xshit");
	y =  my_string_init_c_string("-");
z = my_string_init_c_string("xassa");

//printf ("%d \n", my_string_compare(x,y)); //5
printf ("%d \n", my_string_compare(x,z)); //5
//printf ("%d \n", my_string_compare(y,z)); //5
//printf ("%d \n", my_string_compare(y,x)); //-5
//printf ("%d \n", my_string_compare(z,y)); //-5
printf ("%d \n", my_string_compare(z,x)); //-5

*/

read_dictionary();


	return 0;
}
/*
int tree_insert(Node** pRoot, MY_STRING key, MY_STRING word)
{
    Node* temp;
    Node* temp2;
    Node* temp3;
    int index = 0;
    int prev_factor;
    if (*pRoot == NULL)
    {
        *pRoot = (Node*) malloc(sizeof(Node));
        if (*pRoot == NULL)
        {
            printf("failed to allocate for new node \n");
            exit(1);
        }
        (*pRoot)->key_family = generic_vector_init_default(my_string_assignment, my_string_destroy);
	generic_vector_push_back((*pRoot)->key_family, key);
        (*pRoot)->balance_factor = 0;
        (*pRoot)->word_list = generic_vector_init_default(my_string_assignment, my_string_destroy);
        generic_vector_push_back((*pRoot)->word_list, word);
        (*pRoot)->left = NULL;
        (*pRoot)->right = NULL;
    }
    else
    {

    if (my_string_compare(key, generic_vector_at((*pRoot)->key_family, index)) == 0)
    {
        generic_vector_push_back((*pRoot)->word_list, word);
    }
        prev_factor = (*pRoot)->balance_factor;
        if (my_string_compare(key, generic_vector_at((*pRoot)->key_family, index)) < 0)         // less than root key value
        {
            if(tree_insert(&(*pRoot)->left, key, word))
            {
                (*pRoot)->balance_factor--;

                if ((*pRoot)->balance_factor < -1) // left heavy
                {
                    if(((*pRoot)->left)->balance_factor < 0) // child is left heavy
                    {

                                                            // have to perform right rotation
                        temp = *pRoot;                      // storing address of parent node
                        (*pRoot)->balance_factor+=2;       // increasing balance factor for old root
                        temp2 = ((*pRoot)->left)->right;    // storing address of left child's right child node
                        temp3 = (*pRoot)->left;             // storing address new root
                        *pRoot = temp3;                    // child is now root node
                        (*pRoot)->balance_factor++;       // increasing balance factor for new root
                        temp3->right = temp;             // old root is now new roots right child
                        temp->left = temp2;                 // old roots left child is new roots previous right child
                    }

                    if(((*pRoot)->left)->balance_factor > 0) //child is right heavy
                    {

                                                        // have to perform left right  rotation
                        (*pRoot)->balance_factor+=2;
                        ((*pRoot)->left)->balance_factor-=1;
                        temp = *pRoot;                // storing address of parent node
                        temp2 = (*pRoot)->left;     // storing address left child
                        temp3 = ((*pRoot)->left)->right; // storing address of left childs right child
                        temp3->left = temp2;            // left child will be new roots left child
                        temp3->right = temp;              // old root will be new roots right child
                        *pRoot = temp3;                  // left childs right child is now root
                        temp->left = NULL;   // set pointers to null
                        temp2->right = NULL;  // set pointers to null
                    }
                }

                if((*pRoot)->balance_factor < prev_factor)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }

        else if (my_string_compare(key, generic_vector_at((*pRoot)->key_family, index)) > 0)         // greater than root key value
        {

            if(tree_insert(&(*pRoot)->right, key, word))
            {
                (*pRoot)->balance_factor++;

                if ((*pRoot)->balance_factor > 1) // right heavy
                {
                    if(((*pRoot)->right)->balance_factor > 0) // child is right heavy
                    {

                        // have to perform right left rotation
                        temp = *pRoot;                      // storing address of parent node
                        (*pRoot)->balance_factor-=2;       // decreasing balance factor for old root
                        temp2 = ((*pRoot)->right)->left;    // storing address of left child's right child node
                        temp3 = (*pRoot)->right;             // storing address new root
                        *pRoot = temp3;                    // child is now root node
                        (*pRoot)->balance_factor--;       // decreasing balance factor for new root
                        temp3->left = temp;             // old root is now new roots right child
                        temp->right = temp2;                 // old roots right child is new roots previous right child
                    }

                    if(((*pRoot)->right)->balance_factor < 0) //child is left heavy
                    {

                        // have to perform right left  rotation
                        (*pRoot)->balance_factor-=2;
                        ((*pRoot)->right)->balance_factor+=1;
                        temp = *pRoot;   // storing address of parent node
                        temp2 = (*pRoot)->right;     // storing address left child
                        temp3 = ((*pRoot)->right)->left; // storing address of left childs right child
                        temp3->right = temp2;            // left child will be new roots left child
                        temp3->left = temp;              // old root will be new roots right child
                        *pRoot = temp3;                  // left childs right child is now root
                        temp->right = NULL;   // set pointers to null
                        temp2->left = NULL;  // set pointers to null
                    }
                }

                if((*pRoot)->balance_factor > prev_factor)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }

        }

    }

    return 1;
}
*/
void tree_insert(Node** pRoot, MY_STRING key, MY_STRING word)
{
   // Node* temp;
   // Node* temp2;
   // Node* temp3;
    int index = 0;
    if (*pRoot == NULL)
    {
        *pRoot = (Node*) malloc(sizeof(Node));
        if (*pRoot == NULL)
        {
            printf("failed to allocate for new node \n");
            exit(1);
        }
        (*pRoot)->key_family = generic_vector_init_default(my_string_assignment, my_string_destroy);
	generic_vector_push_back((*pRoot)->key_family, key);
        //(*pRoot)->balance_factor = 0;
        (*pRoot)->word_list = generic_vector_init_default(my_string_assignment, my_string_destroy);
        generic_vector_push_back((*pRoot)->word_list, word);
        (*pRoot)->left = NULL;
        (*pRoot)->right = NULL;

	return;
    }
    else
    {

    if (my_string_compare(key, generic_vector_at((*pRoot)->key_family, index)) == 0)
    {
        generic_vector_push_back((*pRoot)->word_list, word); // if its equal insert into this node
    }

	else if (my_string_compare(key, generic_vector_at((*pRoot)->key_family, index)) < 0)         // less than root key value
        {
            tree_insert(&(*pRoot)->left, key, word); // insert to left node
        }

        else if (my_string_compare(key, generic_vector_at((*pRoot)->key_family, index)) > 0)         // greater than root key value
        {
            tree_insert(&(*pRoot)->right, key, word); // insert to right node
        }



    }

}


void preorder_traversal(Node* root)
{
    if (root != NULL)
    {
         // my_string_insertion(generic_vector_at(root->key_family, index), stdout);
    printf("balance factor %d\n", root->balance_factor);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
    }
    return;
}


void inorder_traversal(Node* root, int *number)
{
    
	if (root != NULL)
    {
    if (*number < generic_vector_get_size(root->word_list))   
	{
		*number = generic_vector_get_size(root->word_list); 
	}
    inorder_traversal(root->left, number);
    //printf("key value");
    //my_string_insertion(generic_vector_at(root->key_family, index), stdout);
    //printf(" number of words %d\n", generic_vector_get_size(root->word_list));
    inorder_traversal(root->right, number);
    }

  
	
    return;
}

void get_largest_family(Node* root, int number, GENERIC_VECTOR hCopy, GENERIC_VECTOR key)
{
    int index;
	int i;
    
    
	

	if (root != NULL)
    {
    if (number == generic_vector_get_size(root->word_list))   
	{
		generic_vector_push_back(key, generic_vector_at(root->key_family, index));		
	for (i = 0; i < generic_vector_get_size(root->word_list); i++)
		{
			generic_vector_push_back(hCopy, generic_vector_at(root->word_list, i));	
		}		
	}
    get_largest_family(root->left, number, hCopy, key);
   
    my_string_insertion(generic_vector_at(root->key_family, index), stdout);
    printf("number of words %d\n", generic_vector_get_size(root->word_list));
    get_largest_family(root->right, number, hCopy, key);
    }
    return;
}


void postorder_traversal(Node* root)
{
    if (root != NULL)
    {
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    }
    return;
}

void tree_destroy (Node** pRoot)
{
    if (*pRoot != NULL)
    {
    tree_destroy(&(*pRoot)->left);
    tree_destroy(&(*pRoot)->right);
    free(*pRoot);
    *pRoot = NULL;
    }
}

void play_hangman(GENERIC_VECTOR word_list, int guesses, int length)
{
    char guess;
    int i;
    int number = 0;
    int guess_number = guesses;
    
    
    Node* root = NULL;
    MY_STRING largest_key = generic_vector_init_default(my_string_assignment, my_string_destroy);
    MY_STRING current_word_family = my_string_init_default();
    GENERIC_VECTOR hCopy = generic_vector_init_default(my_string_assignment, my_string_destroy);
    MY_STRING new_key = my_string_init_default();
    printf("# of words im playing with %d \n", generic_vector_get_size(word_list));
    clearKeyboardBuffer();
	

	for (i = 0; i < length; i++)
    {
        my_string_push_back(current_word_family, '-'); // generates empty key (------)
    }    
    
    printf("Which letter would you like to guess\n");
    scanf("%c", &guess);
	clearKeyboardBuffer();


    for (i = 0; i <generic_vector_get_size(word_list) ; i++)
    {
       get_word_key_value(current_word_family, new_key, generic_vector_at(word_list, i), guess); // gets key value of word
       tree_insert(&root, new_key, generic_vector_at(word_list, i)); // handle to new key handle to MYSTRING opaque object 
    }

    inorder_traversal(root , &number);
    get_largest_family(root, number, hCopy, largest_key);
    printf("word");
    my_string_insertion(generic_vector_at(largest_key, 0), stdout);

    if(!check_key(generic_vector_at(largest_key, 0), guess))
	{		
	guess_number--;
	printf("number of guesses left %d \n", guess_number);
	}
    //my_string_insertion(generic_vector_at(hCopy, 0), stdout);
    tree_destroy(&root);

	while ( guess_number >= 0)
{
clearKeyboardBuffer();   
 printf("Which letter would you like to guess\n");
    scanf("%c", &guess);
	

    for (i = 0; i <generic_vector_get_size(hCopy) ; i++)
    {
       get_word_key_value(current_word_family, new_key, generic_vector_at(hCopy, i), guess); // gets key value of word
       tree_insert(&root, new_key, generic_vector_at(hCopy, i)); // handle to new key handle to MYSTRING opaque object 
    }
		
    inorder_traversal(root , &number);
    get_largest_family(root, number, hCopy, largest_key);
    printf("word");
    my_string_insertion(generic_vector_at(largest_key, 0), stdout);
    tree_destroy(&root);
	    if(!check_key(generic_vector_at(largest_key, 0), guess))
	{		
	guess_number--;
	printf("number of guesses left %d \n", guess_number);
	}

}
}


void read_dictionary(void)
{
    FILE* fp;
    int size = 30;
    int length;
    int guesses;
    GENERIC_VECTOR hVector[size];
    MY_STRING hMy_string;
    hMy_string = my_string_init_default();
    int i;

    fp = fopen("dictionary.txt", "r");

    if (fp == NULL)
    {
	printf("could not open file dictionary.txt for reading\n");
        exit(1);
    }

    for (i = 1; i < size; i++)
    {
        hVector[i] = generic_vector_init_default(my_string_assignment, my_string_destroy);

        if (hVector[i] == NULL)
        {
            printf("Unable to create a generic vector\n");
            exit(1);
        }
    }

    while(my_string_extraction(hMy_string, fp))
    {
        generic_vector_push_back(hVector[my_string_get_size(hMy_string)], hMy_string);
    }

    for (i = 1; i < size; i++)
    {
        printf("there are %d many words of size %d\n", generic_vector_get_size(hVector[i]), i);
    }


    printf("What length word do you want to play with?\n");
    scanf("%d", &length);
    clearKeyboardBuffer();

    printf("How many guesses would you like?\n");
    scanf("%d", &guesses);


    play_hangman(hVector[length], guesses, length);

    fclose(fp);
    for (i = 1; i < size; i++)
    {
        generic_vector_destroy(&hVector[i]);
    }
    my_string_destroy(&hMy_string);

}
void clearKeyboardBuffer(void)
{
    char ch;
    while ((ch = getchar() != '\n') && (ch != EOF));
}
