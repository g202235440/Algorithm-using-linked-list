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
    Node* newlist = linklist(data);//새노드에 data와 *Next값 할당
    if (*head == NULL)//앞에 아무것도 없었으면 
    {
        *head = newlist;//이제부터 방금 한게 1번 리스트가 된다.
        return;
    }
    Node* lastlist = *head;//lastlist는 head를 가리키는 포인터
    while (lastlist->next != NULL)//lastlist에 마지막리스트값을 넣기위해 next가 NULL이 아니면  
    {
        lastlist = lastlist->next;//lastlist에 lastlist 다음값을 넣는다
    }
    lastlist->next = newlist;//lastlist 다음값이 null이 될때 까지 루프가 돌았으니 그 값에 아까 만들었던 새 노드값을 넣는다 여기서 lastlist는 주소값
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
    printf("몇개?\n");
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
            swap(&sample, i + 1); // 인덱스를 1부터 시작하므로 i+1을 전달
            i = i - 1; // 인덱스를 감소시켜 올바른 위치를 찾음
        }
    }

    printList(sample);

}