#include <stdio.h>
#include <stdlib.h>
int Length = 0;
int listL = 0;
int in = 0;
struct Node {
    int data;
    struct Node* next;
};
struct Node* linklist(int data) {
    struct Node* link = (struct Node*)malloc(sizeof(struct Node));
    link->data = data;
    link->next = NULL;
    return link;
}
void comp(int data, Node** head)
{
    Node* newlist = linklist(data);//����忡 data�� *Next�� �Ҵ�
    if (*head == NULL)//�տ� �ƹ��͵� �������� 
    {
        *head = newlist;//�������� ��� �Ѱ� 1�� ����Ʈ�� �ȴ�.
        return;
    }
    Node* lastlist = *head;//lastlist�� head�� ����Ű�� ������
    while (lastlist->next != NULL)//lastlist�� ����������Ʈ���� �ֱ����� next�� NULL�� �ƴϸ�  
    {
        lastlist = lastlist->next;//lastlist�� lastlist �������� �ִ´�
    }
    lastlist->next = newlist;//lastlist �������� null�� �ɶ� ���� ������ �������� �� ���� �Ʊ� ������� �� ��尪�� �ִ´� ���⼭ lastlist�� �ּҰ�
}
int A(int data, Node* node) {
    int count = 1;
    Node* curr = node;
    while (curr != NULL) {
        if (count == data)
        {
            return curr->data;
        }
        count++;
        curr = curr->next;
    }
    return -1;
}

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
        Length++;
    }
    printf("\n");
}
void swap(Node** node, int data) {
    Node* prepre = *node;
    if (data != 2) {
        for (int count = 1; count < data - 2; count++) {
            prepre = prepre->next;
        }
        Node* pre = prepre->next;
        Node* curr = pre->next;
        prepre->next = curr;
        pre->next = curr->next;
        curr->next = pre;
    }
    else
    {
        Node* pre = prepre->next;//3
        prepre->next = pre->next;//1->3
        pre->next = prepre;//2->1
        *node = pre;
    }
}
int main()
{

    Node* sample = NULL;
    printf("�?\n");
    scanf_s("%d", &listL);
    while (in < listL)
    {
        int randomNumber = rand() % listL;
        comp(randomNumber, &sample);
        in++;
    }
    printList(sample);
    for (int j = 2; j <= Length; j++) {
        int i = j - 1;
        int key = A(j, sample);
        while (i > 0 && A(i, sample) > key) {
            swap(&sample, i + 1); // �ε����� 1���� �����ϹǷ� i+1�� ����
            i = i - 1; // �ε����� ���ҽ��� �ùٸ� ��ġ�� ã��
        }
    }

    printList(sample);

}