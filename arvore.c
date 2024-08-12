#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeNode TreeNode;

TreeNode* createNode(int val) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


TreeNode* menorSubarvore(TreeNode* raiz, int* profundidade) {
    if (raiz == NULL) {
        *profundidade = -1; 
        return NULL;
    }

    int profundidadeEsquerda = 0, profundidadeDireita = 0;

    TreeNode* nodoEsquerdo = menorSubarvore(raiz->left, &profundidadeEsquerda);
    TreeNode* nodoDireito = menorSubarvore(raiz->right, &profundidadeDireita);

    if (profundidadeEsquerda > profundidadeDireita) {
        *profundidade = profundidadeEsquerda + 1;
        return nodoEsquerdo;
    }
    else if (profundidadeDireita > profundidadeEsquerda) {
        *profundidade = profundidadeDireita + 1;
        return nodoDireito;
    }

    *profundidade = profundidadeEsquerda + 1;
    return raiz;
}

int main() {
    TreeNode* raiz = createNode(3);
    raiz->left = createNode(5);
    raiz->right = createNode(1);
    raiz->left->left = createNode(6);
    raiz->left->right = createNode(2);
    raiz->right->left = createNode(0);
    raiz->right->right = createNode(8);
    raiz->left->right->left = createNode(7);
    raiz->left->right->right = createNode(4);

    int profundidade;
    TreeNode* subarvore = menorSubarvore(raiz, &profundidade);
    
    
    if (subarvore != NULL) {
        printf("Menor subarvore que contem todos os nos mais profundos: %d\n", subarvore->val);
    } else {
        printf("Nenhuma subárvore encontrada.\n");
    }

 
    return 0;
}
