#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

// Node mới
Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
// them phan tu vao dau danh sach
void addHead(int value)
{
    Node *newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

// them phan tu vao cuoi danh sach
void addTail(int value)
{
    Node *newNode = createNode(value);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Chèn phần tử
void insertAtPosition(int value, int position)
{
    if (position < 1)
    {
        printf("Vi tri khong hop le!\n");
        return;
    }
    if (position == 1)
    {
        addHead(value);
        return;
    }
    Node *newNode = createNode(value);
    Node *temp = head;
    for (int i = 1; i < position - 1; i++)
    {
        if (temp == NULL)
        {
            printf("Vi tri đầy so với danh sach!\n");
            free(newNode);
            return;
        }
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
// xoa phan tu dau dsach
void deleteHead()
{
    if (head == NULL)
    {
        printf("Rỗng!\n");
        return;
    }
    Node *temp = head;
    head = head->next;
    free(temp);
}
// xoa ptu cuoi dsach
void deleteTail()
{
    if (head == NULL)
    {
        printf("Rỗng!\n");
        return;
    }
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// tim kiem ptu theo gtri
void searchByValue(int value)
{
    Node *temp = head;
    int position = 1;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            printf("Gia tri %d tim thay tai vi tri %d\n", value, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Khong tim thay gia tri %d trong danh sach!\n", value);
}

// In danh sách
void displayList()
{
    if (head == NULL)
    {
        printf("Rỗng!\n");
        return;
    }
    Node *temp = head;
    printf("Danh sach: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    Node *head = NULL;
    int value;
    int position;
    do
    {
        printf("\n==================MENU===============\n");
        printf(".1 Thêm phần tử vào đầu danh sách\n");
        printf(".2 Thêm phần tử vào cuối danh sách\n");
        printf(".3 Chèn phần tử vào vị trí cụ thể\n");
        printf(".4 Xóa phần tử đầu danh sách\n");
        printf(".5 Xóa phần tử cuối danh sách\n");
        printf(".6 Xóa phần tử theo giá trị \n");
        printf(".7 Tìm kiếm phần tử theo giá trị\n");
        printf(".8 In danh sách các giá trị ra màn hình\n");
        printf(".9 Thoat\n");
        printf("Chon chuc nang: ");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Nhap gia tri can them : ");
            scanf("%d", &value);
            addHead(value);
            break;
        case 2:
            printf("nhap gia tri can them :");
            scanf("%d", &value);
            addTail(value);
            break;
        case 3:
            printf("Nhap gia tri: ");
            scanf("%d", &value);
            printf("Nhap vi tri: ");
            scanf("%d", &position);
            insertAtPosition(value, position);
            break;
        case 4:
            deleteHead();
            break;
        case 5:
            deleteTail();
            break;
        case 7:
            printf("Nhap gia tri can tim: ");
            scanf("%d", &value);
            searchByValue(value);
            break;
        case 8:
            displayList();
            break;
        default:
            break;
        }
    } while (1 == 1);

    return 0;
}
