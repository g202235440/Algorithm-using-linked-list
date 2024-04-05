#include <stdio.h>
#include <stdlib.h>
#include <time.h>
clock_t start, end,start1,end1;
int Length = 0;//길이를 나타낼 int값이지만 scanf로 길이를 입력받는 경우는 필요없음
int in = 0;

struct Node {//구조체
    int data;
    struct Node* next;
};
struct Node* linklist(int data) {
    struct Node* link = (struct Node*)malloc(sizeof(struct Node));//동적 할당
    link->data = data;//link에 데이터값 할당
    link->next = NULL;//다음 가리키는 값은 NULL로 초기화
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
int A(int data, Node* node) {//A번째 data를 구하기
    int count = 1;//count는 1
    Node* curr = node;//현재값을 구할 노드 생성
    while (curr != NULL) {//노드가 NULL이 아니면 반복
        if (count == data)//count가 data와 같을 때
        {
            return curr->data;//현재 위치의 data를 리턴한다
        }
        count++;//COUNT늘어난다
        curr = curr->next;//다음 curr을 가르키게 한다.
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
    if (data != 2) {//1일떄는 의미 없으니 2일때를 제외한 경우만 만들고 아니면 그냥 a b c중 b와 c를 바꾸는 함수를 만듬
        for (int count = 1; count < data - 2; count++) {
            prepre = prepre->next;
        }
        Node* pre = prepre->next;
        Node* curr = pre->next;
        prepre->next = curr; //대과거는 현재를 가리킴
        pre->next = curr->next;//과거의 는 현재의 다음을 가리킴
        curr->next = pre;//현재는 과거를 가리킴
    }
    else
    {
        Node* pre = prepre->next;//3
        prepre->next = pre->next;//1->3
        pre->next = prepre;//2->1
        *node = pre;//prepre가 노드였던걸 pre로 바꿔야 한다 이는 디버깅 시 prepre는 한칸 앞으로 갔기 때문에 이를쓰지않으면 노드 첫번째값이 사라지게됨
    }
}
//여기부터 머지 소트 함수//////////////////////////////////////////////////
Node* merge(Node* list1, Node* list2) {//list1과 list2를 합치는 함수
    if (list1 == NULL) {
        return list2;
    }
    else if (list2 == NULL) {
        return list1;
    }
    //리스트 1이나 2가 null이면 반댓값을 리턴한다
    Node* result = NULL;//합쳐질 리스트

    if (list1->data <= list2->data) {//리스트2가 더 크거나 같으면 리스트 1을 리턴후 재귀적으로 result의 next값을 다시 merge한다
        result = list1;
        result->next = merge(list1->next, list2);
    }
    else {//위와 동일
        result = list2;
        result->next = merge(list1, list2->next);
    }

    return result;//합쳐진 리스트를 리턴한다
}

Node* mergeSort(Node* head) {//머지소트
    if (head == NULL || head->next == NULL)//예외처리용
        return head;

    Node* mid = head;//가운데를 가리킬 노드
    Node* end = head->next;//끝자리를 가리킬 노드

    while (end != NULL && end->next != NULL) {//end가 두번 움직일때 mid는 한번움직이면서 end가 NULL까지 가서 mid는 가운데를 가리키게 만든다
        mid = mid->next;
        end = end->next->next;
    }

    Node* midL = mid->next;//그후 midL에 mid이후를 넣어 자른다
    mid->next = NULL;//mid이후에 가리키는 것도 잘라준다.

    Node* left = mergeSort(head);//그후 head부터 mid까지 왼쪽 mid->next부터 end까지 right에 저장한다
    Node* right = mergeSort(midL);
    return merge(left, right);//두리스트 merge한다//
}





void txtL(Node* node) {
    FILE* fp;
    fopen_s(&fp, "202235440 전은섭.txt", "a"); // "202235440 전은섭이란 이름의 txt파일을 염

    if (fp == NULL) {//만약 NULL이면 파일 열기 오류
        perror("파일 열기 오류");
        return;
    }

    while (node != NULL) {//노드가 존재하면(쓸게 있으면)
        fprintf(fp, "%d ", node->data); // 노드의 데이터를 파일에 쓰고
        node = node->next; // 다음 노드로 이동 후
    }
    fprintf(fp, "\n");//엔터를 사용
    fclose(fp); // 파일을 닫습니다.
}
void txt(int data) {
    FILE* fp;
    fopen_s(&fp, "202235440 전은섭.txt", "a"); // "202235440 전은섭이란 이름의 txt파일을 염

    if (fp == NULL) {//만약 NULL이면 파일 열기 오류
        perror("파일 열기 오류");
        return;
    }
        fprintf(fp, "걸린 시간 : %d",data); // 노드의 데이터를 파일에 쓰고
        fprintf(fp, "\n");//엔터를 사용
    fclose(fp); // 파일을 닫습니다.
}



int main()
{

    Node* sample = NULL;
    Node* sample1 = NULL;
    printf("몇개?\n");
    scanf_s("%d", &Length);
    while (in < Length)
    {
        int randomNumber = rand() % Length;
        int randomNumber1 = rand() % Length + 1;
        comp(randomNumber, &sample);
        comp(randomNumber1, &sample1);//랜덤으로 수를 뽑아 comp에 넣는 식으로 왜인진 모르겠으나 비슷한 리스트가 많이 생겨서 혹시나 몰라 randomNumber1에는 길이 +1로 최대를 설정한다
        in++;
    }
   printList(sample);
    start = clock();
    for (int j = 2; j <= Length; j++) {//이부분은 책에 나와있는 부분 그대로 사용
        int i = j - 1;
        int key = A(j, sample);
        while (i > 0 && A(i, sample) > key) {
            swap(&sample, i + 1); // 인덱스를 1부터 시작하므로 i+1을 전달
            i = i - 1; // 인덱스를 감소시켜 올바른 위치를 찾음
        }
    }
    end = clock();
    printList(sample);
    int time_taken = (end - start);
    //여기부터는 그냥 출력용
    txtL(sample);
    txt(time_taken);
    start1 = clock();//시간 측정용
    txtL(mergeSort(sample1));
    end1 = clock();
    int time_taken1 = (end1 - start1);
    txt(time_taken1);

}