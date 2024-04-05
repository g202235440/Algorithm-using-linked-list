#include <stdio.h>
#include <stdlib.h>
#include <time.h>
clock_t start, end,start1,end1;
int Length = 0;//���̸� ��Ÿ�� int�������� scanf�� ���̸� �Է¹޴� ���� �ʿ����
int in = 0;

struct Node {//����ü
    int data;
    struct Node* next;
};
struct Node* linklist(int data) {
    struct Node* link = (struct Node*)malloc(sizeof(struct Node));//���� �Ҵ�
    link->data = data;//link�� �����Ͱ� �Ҵ�
    link->next = NULL;//���� ����Ű�� ���� NULL�� �ʱ�ȭ
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
int A(int data, Node* node) {//A��° data�� ���ϱ�
    int count = 1;//count�� 1
    Node* curr = node;//���簪�� ���� ��� ����
    while (curr != NULL) {//��尡 NULL�� �ƴϸ� �ݺ�
        if (count == data)//count�� data�� ���� ��
        {
            return curr->data;//���� ��ġ�� data�� �����Ѵ�
        }
        count++;//COUNT�þ��
        curr = curr->next;//���� curr�� ����Ű�� �Ѵ�.
    }
    return 9999999999;
}

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void swap(Node** node, int data) {
    Node* prepre = *node;
    if (data != 2) {//1�ϋ��� �ǹ� ������ 2�϶��� ������ ��츸 ����� �ƴϸ� �׳� a b c�� b�� c�� �ٲٴ� �Լ��� ����
        for (int count = 1; count < data - 2; count++) {
            prepre = prepre->next;
        }
        Node* pre = prepre->next;
        Node* curr = pre->next;
        prepre->next = curr; //����Ŵ� ���縦 ����Ŵ
        pre->next = curr->next;//������ �� ������ ������ ����Ŵ
        curr->next = pre;//����� ���Ÿ� ����Ŵ
    }
    else
    {
        Node* pre = prepre->next;//3
        prepre->next = pre->next;//1->3
        pre->next = prepre;//2->1
        *node = pre;//prepre�� ��忴���� pre�� �ٲ�� �Ѵ� �̴� ����� �� prepre�� ��ĭ ������ ���� ������ �̸����������� ��� ù��°���� ������Ե�
    }
}
//������� ���� ��Ʈ �Լ�//////////////////////////////////////////////////
Node* merge(Node* list1, Node* list2) {//list1�� list2�� ��ġ�� �Լ�
    if (list1 == NULL) {
        return list2;
    }
    else if (list2 == NULL) {
        return list1;
    }
    //����Ʈ 1�̳� 2�� null�̸� �ݴ��� �����Ѵ�
    Node* result = NULL;//������ ����Ʈ

    if (list1->data <= list2->data) {//����Ʈ2�� �� ũ�ų� ������ ����Ʈ 1�� ������ ��������� result�� next���� �ٽ� merge�Ѵ�
        result = list1;
        result->next = merge(list1->next, list2);
    }
    else {//���� ����
        result = list2;
        result->next = merge(list1, list2->next);
    }

    return result;//������ ����Ʈ�� �����Ѵ�
}

Node* mergeSort(Node* head) {//������Ʈ
    if (head == NULL || head->next == NULL)//����ó����
        return head;

    Node* mid = head;//����� ����ų ���
    Node* end = head->next;//���ڸ��� ����ų ���

    while (end != NULL && end->next != NULL) {//end�� �ι� �����϶� mid�� �ѹ������̸鼭 end�� NULL���� ���� mid�� ����� ����Ű�� �����
        mid = mid->next;
        end = end->next->next;
    }

    Node* midL = mid->next;//���� midL�� mid���ĸ� �־� �ڸ���
    mid->next = NULL;//mid���Ŀ� ����Ű�� �͵� �߶��ش�.

    Node* left = mergeSort(head);//���� head���� mid���� ���� mid->next���� end���� right�� �����Ѵ�
    Node* right = mergeSort(midL);
    return merge(left, right);//�θ���Ʈ merge�Ѵ�//
}





void txtL(Node* node) {
    FILE* fp;
    fopen_s(&fp, "202235440 ������.txt", "a"); // "202235440 �������̶� �̸��� txt������ ��

    if (fp == NULL) {//���� NULL�̸� ���� ���� ����
        perror("���� ���� ����");
        return;
    }

    while (node != NULL) {//��尡 �����ϸ�(���� ������)
        fprintf(fp, "%d ", node->data); // ����� �����͸� ���Ͽ� ����
        node = node->next; // ���� ���� �̵� ��
    }
    fprintf(fp, "\n");//���͸� ���
    fclose(fp); // ������ �ݽ��ϴ�.
}
void txt(int data) {
    FILE* fp;
    fopen_s(&fp, "202235440 ������.txt", "a"); // "202235440 �������̶� �̸��� txt������ ��

    if (fp == NULL) {//���� NULL�̸� ���� ���� ����
        perror("���� ���� ����");
        return;
    }
        fprintf(fp, "�ɸ� �ð� : %d",data); // ����� �����͸� ���Ͽ� ����
        fprintf(fp, "\n");//���͸� ���
    fclose(fp); // ������ �ݽ��ϴ�.
}



int main()
{

    Node* sample = NULL;
    Node* sample1 = NULL;
    printf("�?\n");
    scanf_s("%d", &Length);
    while (in < Length)
    {
        int randomNumber = rand() % Length;
        int randomNumber1 = rand() % Length + 1;
        comp(randomNumber, &sample);
        comp(randomNumber1, &sample1);//�������� ���� �̾� comp�� �ִ� ������ ������ �𸣰����� ����� ����Ʈ�� ���� ���ܼ� Ȥ�ó� ���� randomNumber1���� ���� +1�� �ִ븦 �����Ѵ�
        in++;
    }
   printList(sample);
    start = clock();
    for (int j = 2; j <= Length; j++) {//�̺κ��� å�� �����ִ� �κ� �״�� ���
        int i = j - 1;
        int key = A(j, sample);
        while (i > 0 && A(i, sample) > key) {
            swap(&sample, i + 1); // �ε����� 1���� �����ϹǷ� i+1�� ����
            i = i - 1; // �ε����� ���ҽ��� �ùٸ� ��ġ�� ã��
        }
    }
    end = clock();
    printList(sample);
    int time_taken = (end - start);
    //������ʹ� �׳� ��¿�
    txtL(sample);
    txt(time_taken);
    start1 = clock();//�ð� ������
    txtL(mergeSort(sample1));
    end1 = clock();
    int time_taken1 = (end1 - start1);
    txt(time_taken1);

}