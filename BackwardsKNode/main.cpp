//
//  main.cpp
//  BackwardsKNode
//
//  Created by chenyufeng on 8/9/16.
//  Copyright © 2016 chenyufeng. All rights reserved.
//

#include <iostream>

/**
 *  链表中倒数第k个节点
 *  输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾结点是倒数第1个节点。
 *
 */

using namespace std;

typedef struct NodeLsit{

    int element;
    struct NodeLsit *next;
}Node;

void CreateList(Node **pHead);
void PrintBackwordK(Node *pHead, int k);

int main(int argc, const char * argv[])
{
    Node *pHead;
    CreateList(&pHead);

    PrintBackwordK(pHead, 2);

    return 0;
}

void CreateList(Node **pHead)
{
    cout << "输入节点的每个元素，输入 <=0时结束 " << endl;
    *pHead = new Node;
    memset(*pHead, 0, sizeof(Node));
    (*pHead)->next = NULL;

    Node *pMove = *pHead;

    Node *pNode = new Node;
    memset(pNode, 0, sizeof(Node));
    pNode->next = NULL;

    cin >> pNode->element;
    while (pNode->element > 0)
    {
        pMove->next = pNode;
        pMove = pNode;

        pNode = new Node;
        memset(pNode, 0, sizeof(Node));
        pNode->next = NULL;

        cin >> pNode->element;
    }
}

void PrintBackwordK(Node *pHead, int k)
{
    Node *front = pHead;
    Node *behide = pHead;

    while (--k)
    {
        front = front->next;
    }

    while (front->next != NULL)
    {
        front = front->next;
        behide = behide->next;
    }

    cout << "倒数第K个元素是：" << behide->element << endl;

}











