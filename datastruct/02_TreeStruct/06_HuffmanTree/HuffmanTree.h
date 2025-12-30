#ifndef DATASTRUCT_HUFFMANTREE_H
#define DATASTRUCT_HUFFMANTREE_H
/*Huffman树通过待编码的节点数量，计算出总共的节点个数 m = 2*n - 1
 * 用数组0的单位表示无效节点，从1号单元开始填充，那么申请2*n个空间*/
typedef struct {
    int weight;         //节点的权值
    int parent;         //还节点的覅节点编号，0值表示该节点就是根
    int lChild,rChild;  //指向该节点的左右孩子节点的编号
}HuffmanNode, *HuffmanTree;

HuffmanTree createHuffmanTree(const int *w,int n);
void releaseHuffmanTree(HuffmanTree tree);

/*Huffman编码，用一个字符空间来保存每个符号的编码字符串
 * char *codes[n];HuffmanCode codes[n];*/
typedef char* HuffmanCode;
HuffmanCode* createHuffmanCodes(HuffmanTree tree,int n);
void releaseHuffmanCodes(HuffmanCode *codes,int n);

#endif //DATASTRUCT_HUFFMANTREE_H
