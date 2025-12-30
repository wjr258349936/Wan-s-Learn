#include <stdlib.h>
#include <string.h>
#include "HuffmanTree.h"

static void selectTwoMin(HuffmanTree tree,int n,int* s1,int* s2){
    *s1 = *s2 = 0;
    for(int i=1;i<=n;++i){              //在1~n里面选择尚未被选择过的节点，且保证s1权值始终小于s2
        if(tree[i].parent==0){
            if(*s1 == 0){
                *s1=i;
            }else if(*s2 == 0){
                *s2=i;
                if(tree[*s1].weight>tree[*s2].weight){
                    int t = *s1;
                    *s1 = *s2;
                    *s2 = t;
                }
            }else {
                //比较权值大小，更新最小的两个节点下标
                if(tree[i].weight<tree[*s1].weight){
                    *s2 = *s1;
                    *s1 = i;
                }else if(tree[i].weight<tree[*s2].weight){
                    *s2 = i;
                }
            }
        }
    }
}

HuffmanTree createHuffmanTree(const int *w, int n) {
    int m=2*n-1;
    HuffmanTree tree = malloc(sizeof(HuffmanNode)*(m+1));
    if(tree==NULL){
        return NULL;
    }
    //2.1 初始化1 ~ 2n-1 个节点
    for(int i =1;i<=m;++i){
        tree[i].parent = tree[i].lChild = tree[i].rChild = 0;
        tree[i].weight=0;
    }
    //2.2 初始化权值1 ~ n
    for(int i=1;i<=n;++i){
        tree[i].weight = w[i-1];
    }
    //初始化借书，开始构建HuffmanTree
    //填充从n+1下标到m下标的空间
    int s1,s2;      //没有parent约束的两个最小的权值
    for(int i=n+1;i<=m;++i){
        //在[1...i-1]范围内，父节点为0，权值最小的两个
        selectTwoMin(tree,i-1,&s1,&s2);
        //将这2个权值最小的节点，组合刀第i个位置
        tree[s1].parent = tree[s2].parent = i;
        tree[i].lChild = s1;tree[i].rChild = s2;
        tree[i].weight = tree[s1].weight + tree[s2].weight;
    }
    return tree;
}

void releaseHuffmanTree(HuffmanTree tree) {
    if(tree){
        free(tree);
    }
}

//从n个叶子结点才找到根节点，你想求每个叶子的对应的编码
HuffmanCode *createHuffmanCodes(HuffmanTree tree, int n) {
    //申请了一个数组空间，每个元素都保存一个地址，这个地址指向了对应元素的编码结果
    HuffmanCode *codes = malloc(sizeof (HuffmanCode)*n);
    if(codes == NULL){
        return NULL;
    }
    memset(codes,0,sizeof (HuffmanCode)*n);
    //生成每个符号对应的编码结果
    //n个节点，树的高度最大为n，而HuffmanTree要低于任意树的最大值
    char *temp = malloc(sizeof (char)*(n+1));
    for(int i=1;i<=n;++i){
        int start = n-1;        //表示temp空间的编码起始位置，从后往前编码，编码临时结果从后往前
        temp[start] = '\0';
        int pos = i;            //当前正在编码的位置
        int p = tree[i].parent; //存放当前节点的父节点信息
        while(p) {
            --start;
            temp[start] = (tree[p].lChild == pos) ? '0' : '1';
            pos = p;
            p = tree[p].parent;
        }
        //将第i个字符编码进行填充
        codes[i - 1] = malloc(sizeof(char) * (n - start));
        strcpy(codes[i - 1], &temp[start]);
    }
    free(temp);
    return codes;
}

void releaseHuffmanCodes(HuffmanCode *codes, int n) {
    if(codes){
        for(int i=0;i<n;++i){
            if(codes[i]){
                free(codes[i]);
            }
        }
        free(codes);
    }
}

