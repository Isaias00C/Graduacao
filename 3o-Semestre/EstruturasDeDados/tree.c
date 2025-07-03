#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct __treeNode_{
    int size; // tamanho do dado
    char *data; // buffer para armazenar o dado
    int height; // profundidade do nó

    char *parent; // ponteiro para o nó pai
    char *leftNode; // ponteiro para o nó da esquerda
    char *rightNode; // ponteiro para o nó da direita
}Node;

Node *createNode(char *data, int size);
bool destroyNode(Node *node);
bool setRight(Node *parent, Node *node);
bool setLeft(Node *parent, Node *node);
bool setParent(Node *node, Node *parent);
Node *getRight(Node *node);
Node *getLeft(Node *node);
Node *getParent(Node *node);
bool setHeight(Node *node, int height);
int getHeight(Node *node);
bool getData(Node *node, char *data);
int getSize(Node *node);

typedef struct __binaryTree_{
    int numberNodes;
    int maxNumberNodes;
    int dataSize;
    Node *root;
    int maxheight;
}BinaryTree;

bool createBinaryTree(BinaryTree *tree, int dataSize, int maxNumberNodes);
bool destroyBinaryTree(BinaryTree *tree);
bool addNode(BinaryTree *tree, char *data);
bool addNodeRec(BinaryTree *tree, Node *currNode, char *data);
bool deleteNode(BinaryTree *tree, char *data);
void showTree(BinaryTree *tree);
void showTreeRec(BinaryTree *tree, Node *node);

int main(){
    BinaryTree tree;
    createBinaryTree(&tree, sizeof(int), 5);
    int data1 = 12;
    int data2 = 4;
    int data3 = 6;
    int data4 = 1;
    int data5 = 20;

    addNode(&tree, (char*)&data1);
    addNode(&tree, (char*)&data2);
    addNode(&tree, (char*)&data3);
    addNode(&tree, (char*)&data4);
    addNode(&tree, (char*)&data5);

    showTree(&tree);
    
    return 0;
}

// metodo de comparação

int max(int a, int b){
    return a > b ? a : b;
}

// metodos para o nó

Node *createNode(char *data, int size){
    Node *node;

    if((node = malloc(sizeof(Node))) == NULL){
        printf("ERROR: erro ao alocar memoria para o nó\n");
        return NULL;
    }
    
    if((node->data = (char*)malloc(size)) == NULL) {
        free(node);
        return NULL;
    }

    memcpy(node->data, data, size);

    node->size = size;
    node->height = 0;

    node->parent = NULL;
    node->leftNode = NULL;
    node->rightNode = NULL;

    return node;
}

bool destroyNode(Node *node){
    if(node == NULL) {
        printf("ERROR: no nulo");
        return false;
    }
    if(node->rightNode != NULL || node->leftNode != NULL){
        printf("ERROR: no nao pode ser destruido");
        return false;
    }

    free(node->data);
    free(node);
    return true;
}

bool setRight(Node *parent, Node *node){
    if(!parent || !node){
        printf("Algum ponteiro nulo");
        return false;
    }

    parent->rightNode = (char*)node;
}

bool setLeft(Node *parent, Node *node){
    if(!parent || !node){
        printf("Algum ponteiro nulo");
        return false;
    }

    parent->leftNode = (char*)node;
}

bool setParent(Node *node, Node *parent){
    if(!parent || !node){
        printf("Algum ponteiro nulo");
        return false;
    }

    node->parent = (char*)parent;
}

Node *getRight(Node *node){
    return (Node*)node->rightNode;
}

Node *getLeft(Node *node){
    return (Node*)node->leftNode;
}

Node *getParent(Node *node){
    return (Node*)node->parent;
}

bool setHeight(Node *node, int height){
    return false;
}

int getHeight(Node *node){
    return node->height;
}

bool getData(Node *node, char *data){
    memcpy(data, node->data, node->size);
    return true;
}

int getSize(Node *node){
    return node->size;
}

void showNode(Node *node){
    for(int i = 0; i < (node->height-1)*10; ++i) printf(" ");
    printf("%d\n\n", *(int*)(node->data));
}

// metodos para a arvore

bool createBinaryTree(BinaryTree *tree, int dataSize, int maxNumberNodes){
    tree->dataSize = dataSize;
    tree->maxNumberNodes = maxNumberNodes;
    tree->maxheight = 0;
    tree->root = NULL;
    tree->numberNodes = 0;

    return true;
}

bool destroyBinaryTree(BinaryTree *tree){
    Node *currNode = tree->root;

    while(tree->numberNodes){
        if(!destroyNode(currNode)){
            if(currNode->leftNode != NULL){
                currNode = (Node*)currNode->leftNode;
            }else if(currNode->rightNode != NULL){
                currNode = (Node*)currNode->rightNode;
            }
        }else{
            tree->numberNodes--;
            if(tree->numberNodes != 0) currNode = tree->root;
        }
    }

    free(tree);
}

bool addNode(BinaryTree *tree, char *data){
    if(data == NULL){
        printf("ERROR: data invalida");
        return false;
    }
    
    if(tree == NULL) {
        printf("ERROR: arvore nula\n");
        return false;
    }

    if(tree->numberNodes == 0){
        Node *node = createNode(data, tree->dataSize);
        
        tree->root = node;
        tree->numberNodes++;
        tree->maxheight = 1;
        node->height = 1;
        return true;
    }

    return addNodeRec(tree, tree->root, data);
}

bool addNodeRec(BinaryTree *tree, Node *currNode, char *data){
    if(*(int*)(currNode->data) > *(int*)(data) && currNode->leftNode != NULL) return addNodeRec(tree, (Node*)currNode->leftNode, data);
    if(*(int*)(currNode->data) > *(int*)(data) && currNode->leftNode == NULL) {
        Node *node = createNode(data, tree->dataSize);
        setParent(node, currNode);
        setLeft(currNode, node);

        node->height = currNode->height + 1;

        tree->maxheight = max(node->height, tree->maxheight);

        tree->numberNodes++;

        return true;
    }

    if(*(int*)(currNode->data) < *(int*)(data) && currNode->rightNode != NULL) return addNodeRec(tree, (Node*)currNode->rightNode, data);
    if(*(int*)(currNode->data) < *(int*)(data) && currNode->rightNode == NULL) {
        Node *node = createNode(data, tree->dataSize);
        setParent(node, currNode);
        setRight(currNode, node);

        node->height = currNode->height + 1;

        tree->maxheight = max(node->height, tree->maxheight);
        
        tree->numberNodes++;

        return true;
    }

    printf("ERROR: valor ja existe na arvore\n");
    return false;
}

bool deleteNode(BinaryTree *tree, char* data){
    return true;
}

void showTree(BinaryTree *tree){
    showTreeRec(tree, tree->root);
}

void showTreeRec(BinaryTree *tree, Node *currNode){
    if(currNode->rightNode != NULL) showTreeRec(tree, (Node*)currNode->rightNode);
    showNode(currNode);
    if(currNode->leftNode != NULL) showTreeRec(tree, (Node*)currNode->leftNode);
}
