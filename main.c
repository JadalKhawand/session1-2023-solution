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
