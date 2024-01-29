#include <stdio.h>
#include <stdlib.h>
#define size 50
typedef struct Product
{
    char name[size];
    int id;
    float price;
    int quantity;
} Product;

typedef struct NodeP
{
    Product product;
    struct NodeP *next;
} NodeP;



typedef struct Store
{
    char name[size];
    char address[size];
    NodeP *products; // pointer to the first product
} Store;

typedef struct Node{
    int data;
    Node *next;
}Node;

int getQuantity(Store *s, int id)
{
    NodeP* current = s->products;
    while(current)
    {
        if(current->product.id == id)
            return current->product.quantity;
        current = current->next;
    }
    printf("product with id: %d was not found",id);
    return -1;
}

void AddProduct(Store *s, Product p){
    NodeP* current = s->products;
    while(current)
    {
        if(current->product.id == p.id)
            current->product.quantity += p.quantity;
            return;
        current = current->next;
    }
    NodeP* newNode = (NodeP*)malloc(sizeof(NodeP));
    if(!newNode)
        exit(EXIT_FAILURE);
    newNode->product = p;
    newNode->next = s->products;
    s->products = newNode;
}

void SaveProducts(Store *s){
    FILE *file = fopen("products.dat","wb");
    if(!file)
        return;
    NodeP *current = s->products;
    while (current) {
        fwrite(&(current->product), sizeof(Product), 1, file);
        current = current->next;
    }

    if(fclose(file))
        printf("Error saving the file.");
}

void updateProductPrice(int id, float price){
    FILE *file = fopen("products.dat","rb+");
    if(!file)
    {
        printf("Failed to open file for reading and writing.");
        return;
    }
    Product product;
    while(fread(&product, sizeof(Product),1,file)){
        if(product.id = id){
            product.price = price;
            fseek(file,-sizeof(Product),SEEK_CUR);
            fwrite(&product, sizeof(Product),1,file);
            printf("Price updated");
            fclose(file);
            return;
        }
    }
    printf("Product with ID %d not found\n", id);
    fclose(file);
}

Node* partition(Node *head, int input) {
    Node *lessThan = NULL;
    Node *greaterThanOrEqual = NULL;
    Node *lessThanEnd = NULL;
    Node *current = head;

    while (current != NULL) {
        Node *temp = current->next;

        if (current->value < input) {
//If lessThan is NULL, we set both lessThan and lessThanEnd to current.
            if (lessThan == NULL) {
                lessThan = current;
                lessThanEnd = current;
// we append current to the end of the lessThan list and update lessThanEnd.
            } else {
                lessThanEnd->next = current;
                lessThanEnd = current;
            }
            lessThanEnd->next = NULL;  // Set the next pointer of the last node to NULL
        } else {
            current->next = greaterThanOrEqual;
            greaterThanOrEqual = current;
        }
        current = temp;

    // Concatenate the two lists
    if (lessThan == NULL) {
        return greaterThanOrEqual;
    } else {
        lessThanEnd->next = greaterThanOrEqual;



void display(NodeP* head)
{
    if(!head)
        return;
    printf("%d",head->product.name);
    display(head->next);
}

int main()
{


    return 0;
}
