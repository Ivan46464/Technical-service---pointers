

#include <iostream>
#include <cstring> 
#include <algorithm>
#include <cstring >
using namespace std;
struct Order {
    unsigned int Order_number = 0;
    unsigned int Order_dayofmonth = 0;
    char Order_client[20];
    char Order_typeofdevice[20];
    char Order_id[20];
    char Order_problem[50];
    char Order_nameoftechnik[20];
    char Order_what_order[20];
    char Order_repair_done[50];
    double Order_price = 0;
    int index = 0;
    int index2 = 0;
    char Order_days_of_downtime[20];
    char Order_status[20] = { "" };

    Order* prev;
    Order* next;
}*head = nullptr,
* tail = nullptr;


void Add_order(Order*& head, Order*& tail, int& Number_of_made_orders) {
    int number_of_orders;
    cout << "Number of orders: ";
    cin >> number_of_orders;
    for (int i = Number_of_made_orders; i < Number_of_made_orders + number_of_orders; i++) {
        Order* newNode = new Order;
        newNode->prev = nullptr;
        newNode->next = nullptr;

        cout << "Order number: ";
        while (!(cin >> newNode->Order_number) || newNode->Order_number <= 0 || newNode->Order_number != i + 1) {
            cout << "Enter a valid number, please. The number you inputted is either passed order or order which will be made."<< endl;
            if (head == nullptr) {
                cout << "This is the first order so write 1"<<endl;
            }
            else {
                cout << "The last number was:" << tail->Order_number<<endl;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Day of the month: ";
        while (!(cin >> newNode->Order_dayofmonth) || newNode->Order_dayofmonth < 1 || newNode->Order_dayofmonth > 31) {
            cout << "Enter a valid day of the month, please.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        //bool isDayOfMonthValid = (i == 0 ? 1 : head->Order_dayofmonth) <= newNode->Order_dayofmonth;
        //if (i == 0 && (newNode->Order_dayofmonth < 1 || newNode->Order_dayofmonth > 31)) {
        //    cout << "You cannot input a date that is outside the limit of one month. Current date is: 1\n";
        //    cin >> newNode->Order_dayofmonth;
        //}

        //while (newNode->Order_dayofmonth > 31) {
          //  cout << "You cannot input a date that is outside the limit of one month. Current date is: " << head->Order_dayofmonth << endl;
         //   cin >> newNode->Order_dayofmonth;
      //  }

        //while (!isDayOfMonthValid) {
        //    isDayOfMonthValid = (i == 0 ? 1 : head->Order_dayofmonth) <= newNode->Order_dayofmonth;
        //    if (isDayOfMonthValid)
        //        break;
        //
        //    cout << "You cannot input a date that has already passed. Current date is: " << head->Order_dayofmonth << endl;
        //    cin >> newNode->Order_dayofmonth;
        //}
        cout << "Client's name: ";
        cin.ignore(1000, '\n');
        cin.getline(newNode->Order_client, 20);

        cout << "Type of the device: ";
        cin.getline(newNode->Order_typeofdevice, 20);

        cout << "Technic's name: ";
        cin.getline(newNode->Order_nameoftechnik, 20);

        cout << "Orders id: ";
        cin.getline(newNode->Order_id, 20);

        cout << "What problem do you have:\n";
        cout << "1. Problem with the screen." << endl;
        cout << "2. Problem with the CPU." << endl;
        cout << "3. Problem with the GPU." << endl;
        cout << "4. Problem with the keyboard." << endl;
        cout << "5. Problem with the videocard." << endl;
        cout << "6. Problem with the software." << endl;
        cout << "7. Problem with the touchpad." << endl;
        cout << "8. Problem with the mouse." << endl;
        cout << "9. Problem with the battery." << endl;
        cout << "10. Problem with the memory." << endl;

        int choiceForProblem;
        cout << "Pick a problem: ";
        while (!(cin >> choiceForProblem) || choiceForProblem > 10) {
            cout << "Try with a problem we can solve.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choiceForProblem) {
        case 1: strcpy_s(newNode->Order_problem, sizeof(newNode->Order_problem), "Problem with the screen."); break;
        case 2: strcpy_s(newNode->Order_problem, sizeof(newNode->Order_problem), "Problem with the CPU."); break;
        case 3: strcpy_s(newNode->Order_problem, sizeof(newNode->Order_problem), "Problem with the GPU."); break;
        case 4: strcpy_s(newNode->Order_problem, sizeof(newNode->Order_problem), "Problem with the keyboard."); break;
        case 5: strcpy_s(newNode->Order_problem, sizeof(newNode->Order_problem), "Problem with the videocard."); break;
        case 6: strcpy_s(newNode->Order_problem, sizeof(newNode->Order_problem), "Problem with the software."); break;
        case 7: strcpy_s(newNode->Order_problem, sizeof(newNode->Order_problem), "Problem with the touchpad."); break;
        case 8: strcpy_s(newNode->Order_problem, sizeof(newNode->Order_problem), "Problem with the mouse."); break;
        case 9: strcpy_s(newNode->Order_problem, sizeof(newNode->Order_problem), "Problem with the battery."); break;
        case 10: strcpy_s(newNode->Order_problem, sizeof(newNode->Order_problem), "Problem with the memory."); break;
        }
        cout << "-------------------------------------\n";

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    Number_of_made_orders += number_of_orders;
}
int Cstring_compare1(char str1[], string str2)  
{
    int index = 0;
    int res = str2.compare(str1);
    if (res == 0)
        index++;
    return index;
}
void Display_order(Order* order) {
    cout << "Order number: " << order->Order_number << endl;
    cout << "Day of the month: " << order->Order_dayofmonth << endl;
    cout << "Client's name: " << order->Order_client << endl;
    cout << "Type of the device: " << order->Order_typeofdevice << endl;
    cout << "Order id: " << order->Order_id << endl;
    cout << "Problem: " << order->Order_problem << endl;
    cout << "Technician's name: " << order->Order_nameoftechnik << endl;
    cout << "Order status: " << order->Order_status << endl;
    cout << "-------------------------------------\n";
}
void Collect_and_sort_orders_with_bubleSort(Order* head) {
    
    int count = 0;
    Order* currentNode = head;
    while (currentNode != nullptr) {
        count++;
        currentNode = currentNode->next;
    }

    
    Order** orderArray = new Order * [count];
    int index = 0;

    
    currentNode = head;
    while (currentNode != nullptr) {
        orderArray[index] = currentNode;
        index++;
        currentNode = currentNode->next;
    }

    
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (orderArray[j]->Order_number > orderArray[j + 1]->Order_number) {
                
                Order* temp = orderArray[j];
                orderArray[j] = orderArray[j + 1];
                orderArray[j + 1] = temp;
            }
        }
    }

   
    for (int i = 0; i < count; i++) {
        Order* currentOrder = orderArray[i];
        cout << "Order number: " << currentOrder->Order_number << endl;
        cout << "Day of the month: " << currentOrder->Order_dayofmonth << endl;
        cout << "Client's name: " << currentOrder->Order_client << endl;
        cout << "Type of the device: " << currentOrder->Order_typeofdevice << endl;
        cout << "Order id: " << currentOrder->Order_id << endl;
        cout << "Problem: " << currentOrder->Order_problem << endl;
        cout << "Technik's name: " << currentOrder->Order_nameoftechnik << endl;
        cout << "Order status: " << currentOrder->Order_status << endl;
        cout << "-------------------------------------\n";
    }

    
    delete[] orderArray;
}
void Bubble_sort_order_by_number_descending(const Order* head)
{
    if (head == nullptr)
    {
        cout << "The list is empty." << endl;
        return;
    }

    Order* newHead = nullptr;
    Order* current = nullptr;
    Order* prev = nullptr;

    while (head != nullptr)
    {
        current = new Order(*head);
        current->prev = prev;

        if (prev != nullptr)
        {
            prev->next = current;
        }

        if (newHead == nullptr)
        {
            newHead = current;
        }

        prev = current;
        head = head->next;
    }

    bool swapped;
    Order* last = nullptr;

    do
    {
        swapped = false;
        current = newHead;

        while (current->next != last)
        {
            if (current->Order_number < current->next->Order_number)
            {
                swap(current->Order_number, current->next->Order_number);
                swap(current->Order_dayofmonth, current->next->Order_dayofmonth);
                swap(current->Order_typeofdevice, current->next->Order_typeofdevice);
                swap(current->Order_problem, current->next->Order_problem);
                swap(current->Order_nameoftechnik, current->next->Order_nameoftechnik);
                swap(current->Order_typeofdevice, current->next->Order_typeofdevice);
                swap(current->Order_status, current->next->Order_status);
                swap(current->Order_id, current->next->Order_id);
                
                swapped = true;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);

    current = newHead;

    while (current != NULL)
    {
        cout << "Order Number: " << current->Order_number << endl;
        cout << "Day of the Month: " << current->Order_dayofmonth << endl;
        cout << "Client's Name:" << current->Order_client << endl;
        cout << "Type of the Device:" << current->Order_typeofdevice << endl;
        cout << "Order ID:" << current->Order_id << endl;
        cout << "Problem:" << current->Order_problem << endl;
        cout << "Status:" << current->Order_status << endl;
        cout << "-------------------------------------\n";
        current = current->next;
    }

    current = newHead;

    while (current != nullptr)
    {
        Order* next = current->next;
        delete current;
        current = next;
    }
}
void Display_orders(const Order* head) {
    cout << "Orders:\n";

    const Order* current = head;
    while (current != nullptr) {
        cout << "Order Number: " << current->Order_number << endl;
        cout << "Day of the Month: " << current->Order_dayofmonth << endl;
        cout << "Client's Name:" << current->Order_client << endl;
        cout << "Type of the Device:" << current->Order_typeofdevice << endl;
        cout << "Technician's name:" << current->Order_nameoftechnik << endl;
        cout << "Order ID:" << current->Order_id << endl;
        cout << "Problem:" << current->Order_problem << endl;
        cout << "Status:" << current->Order_status << endl;
        cout << "-------------------------------------\n";

        current = current->next;
    }
}
bool Binary_search(const char* arr[], int left, int right, const char* target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int compareResult = strcmp(arr[mid], target);

        if (compareResult == 0) {
            return true;  
        }
        else if (compareResult < 0) {
            left = mid + 1;  
        }
        else {
            right = mid - 1;  
        }
    }

    return false;  
}
void Search_and_display_orders_by_status_with_bynary_search(Order* head) {
    char target[20];
    cin.ignore();
    cout << "Enter the Order_status to search for: ";
    cin.getline(target, 20);
     

    
    int count = 0;
    Order* currentNode = head;
    while (currentNode != nullptr) {
        count++;
        currentNode = currentNode->next;
    }

    const char** typeArray = new const char* [count];
    int index = 0;

    currentNode = head;
    while (currentNode != nullptr) {
        typeArray[index] = currentNode->Order_status;
        index++;
        currentNode = currentNode->next;
    }

    
    sort(typeArray, typeArray + count, [](const char* a, const char* b) {
        return strcmp(a, b) < 0;
        });

    
    bool found = Binary_search(typeArray, 0, count - 1, target);

    if (found) {
        currentNode = head;
        while (currentNode != nullptr) {
            int compareResult = strcmp(currentNode->Order_status, target);
            if (compareResult == 0) {
                cout << "Order number: " << currentNode->Order_number << endl;
                cout << "Day of the month: " << currentNode->Order_dayofmonth << endl;
                cout << "Client's name: " << currentNode->Order_client << endl;
                cout << "Type of the device: " << currentNode->Order_typeofdevice << endl;
                cout << "Technician's name:" << currentNode->Order_nameoftechnik << endl;
                cout << "Order id: " << currentNode->Order_id << endl;
                cout << "What problem do you have: " << currentNode->Order_problem << endl;
                cout << "Order status: " << currentNode->Order_status << endl;
                cout << "---------------------------------\n";
            }
            currentNode = currentNode->next;
        }
    }
    else {
        cout << "No orders found for the specified device type.\n";
    }
}
void Search_by_type_of_device_with_bynary_search(Order* head) {
    char target[20];
    cout << "Type the device that you are looking for:\n";
    cin >> target;

    
    int count = 0;
    Order* currentNode = head;
    while (currentNode != nullptr) {
        count++;
        currentNode = currentNode->next;
    }

    const char** typeArray = new const char* [count];
    int index = 0;

    currentNode = head;
    while (currentNode != nullptr) {
        typeArray[index] = currentNode->Order_typeofdevice;
        index++;
        currentNode = currentNode->next;
    }

    
    sort(typeArray, typeArray + count, [](const char* a, const char* b) {
        return strcmp(a, b) < 0;
        });

    
    bool found = Binary_search(typeArray, 0, count - 1, target);

    if (found) {
        currentNode = head;
        while (currentNode != nullptr) {
            int compareResult = strcmp(currentNode->Order_typeofdevice, target);
            if (compareResult == 0) {
                cout << "Order number: " << currentNode->Order_number << endl;
                cout << "Day of the month: " << currentNode->Order_dayofmonth << endl;
                cout << "Client's name: " << currentNode->Order_client << endl;
                cout << "Type of the device: " << currentNode->Order_typeofdevice << endl;
                cout << "Technician's name:" << currentNode->Order_nameoftechnik << endl;
                cout << "Order id: " << currentNode->Order_id << endl;
                cout << "What problem do you have: " << currentNode->Order_problem << endl;
                cout << "Order status: " << currentNode->Order_status << endl;
                cout << "---------------------------------\n";
            }
            currentNode = currentNode->next;
        }
    }
    else {
        cout << "No orders found for the specified device type.\n";
    }
}
void Search_by_technik_and_sort_with_selection_sort(Order* head) {
    string target;
    cout << "Type the technik that you are looking for:\n";
    cin >> target;

    
    int count = 0;
    Order* currentNode = head;
    while (currentNode != nullptr) {
        int compareResult = Cstring_compare1(currentNode->Order_nameoftechnik, target);
        int compareResult1 = Cstring_compare1(currentNode->Order_status, "Finished order");

        if (compareResult == 1 && compareResult1 == 1) {
            count++;
        }

        currentNode = currentNode->next;
    }

    Order* matchingOrdersArray = new Order[count];
    int index = 0;

    currentNode = head;
    while (currentNode != nullptr) {
        int compareResult = Cstring_compare1(currentNode->Order_nameoftechnik, target);
        int compareResult1 = Cstring_compare1(currentNode->Order_status, "Finished order");

        if (compareResult == 1 && compareResult1 == 1) {
            matchingOrdersArray[index] = *currentNode;
            index++;
        }

        currentNode = currentNode->next;
    }

    
    for (int i = 0; i < count - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < count; j++) {
            if (matchingOrdersArray[j].Order_dayofmonth < matchingOrdersArray[minIndex].Order_dayofmonth) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            
            Order temp = matchingOrdersArray[i];
            matchingOrdersArray[i] = matchingOrdersArray[minIndex];
            matchingOrdersArray[minIndex] = temp;
        }
    }

    
    for (int i = 0; i < count; i++) {
        Order currentOrder = matchingOrdersArray[i];
        cout << "Order number: " << currentOrder.Order_number << endl;
        cout << "Day of the month: " << currentOrder.Order_dayofmonth << endl;
        cout << "Client's name: " << currentOrder.Order_client << endl;
        cout << "Technik's name: " << currentOrder.Order_nameoftechnik << endl;
        cout << "Type of the device: " << currentOrder.Order_typeofdevice << endl;
        cout << "Order id: " << currentOrder.Order_id << endl;
        cout << "What problem do you have: " << currentOrder.Order_problem << endl;
        cout << "Order status: " << currentOrder.Order_status << endl;
        cout << "---------------------------------\n";
    }

    if (count == 0) {
        cout << "No orders found for the specified technik.\n";
    }

    delete[] matchingOrdersArray;
}
void Sort_by_date_with_array_10_with_exchange_sort(Order* head) {
    const int maxElements = 10;  
    Order* currentNode = head;
    Order* orderArray[maxElements];
    int count = 0;

    
    while (currentNode != nullptr && count < maxElements) {
        orderArray[count] = currentNode;
        currentNode = currentNode->next;
        count++;
    }

    
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (orderArray[i]->Order_dayofmonth > orderArray[j]->Order_dayofmonth) {
                
                Order* temp = orderArray[i];
                orderArray[i] = orderArray[j];
                orderArray[j] = temp;
            }
        }
    }

    
   for (int i = 0; i < count; i++) {
       Order* currentOrder = orderArray[i];
       cout << "Order number: " << currentOrder->Order_number << endl;
       cout << "Day of the month: " << currentOrder->Order_dayofmonth << endl;
       cout << "Client's name: " << currentOrder->Order_client << endl;
       cout << "Type of the Device:" << currentOrder->Order_typeofdevice << endl;
       cout << "Technician's name:" << currentOrder->Order_nameoftechnik << endl;
       cout << "Order ID:" << currentOrder->Order_id << endl;
       cout << "Problem:" << currentOrder->Order_problem << endl;
       cout << "Status:" << currentOrder->Order_status << endl;
       cout << "-------------------------------------\n";
   }
}
void Order_status(Order* head, int& Number_of_made_orders) {
    unsigned int write_order_number1;
    cout << "Write the number of the order to update it:\n";
    while (!(cin >> write_order_number1)) {
        cout << "Enter number please.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    bool orderFound = false;
    Order* currentNode = head;
    while (currentNode != nullptr) {
        if (write_order_number1 == currentNode->Order_number) {
            orderFound = true;
            int number7 = Cstring_compare1(currentNode->Order_status, "");
            int number8 = Cstring_compare1(currentNode->Order_status, "Accepted order");
            int number9 = Cstring_compare1(currentNode->Order_status, "Finished order");
            if (number7 == 0 && number8 == 0 && number9 == 1) {
                cout << "This order is finished, so its status cannot be changed.\n";
            }
            int number4 = Cstring_compare1(currentNode->Order_status, "");
            int number5 = Cstring_compare1(currentNode->Order_status, "Accepted order");
            int number6 = Cstring_compare1(currentNode->Order_status, "Denied order");
            if (number4 == 0 && number5 == 0 && number6 == 1) {
                cout << "This order is denied, so its status cannot be changed.\n";
            }            
            int number = Cstring_compare1(currentNode->Order_status, "");
            if (number == 1) {
                currentNode->index += 1;
                cout << "Pick order status:\n";
                cout << "1.Accepted order\n";
                cout << "2.Denied order\n";
                cout << "3.Finished order\n";
                int orderstatus;
                cout << "Pick:\n";
                while (!(cin >> orderstatus) || orderstatus > 3) {
                    cout << "Enter a number between 1, 2 and 3, please.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                switch (orderstatus) {
                case 1: strcpy_s(currentNode->Order_status, "Accepted order"); break;
                case 2: strcpy_s(currentNode->Order_status, "Denied order"); break;
                case 3: strcpy_s(currentNode->Order_status, "Finished order"); break;
                }
            }
          
        }
        currentNode = currentNode->next;
    }

    if (!orderFound) {
        cout << "This order does not exist.\n";
    }
}
void Collect_and_sort_orders_for_problem_1_with_insertion_sort(Order* head) {
    char target[50] ;
    cout << "Type the problem that you are looking for:\n";
    cin.ignore(); 
    cin.getline(target, 50);
    int count = 0;
    Order* currentNode = head;
    
    
    while (currentNode != nullptr) {
        if (Cstring_compare1(currentNode->Order_problem, target) == 1) {
            count++;
        }
        currentNode = currentNode->next;
    }

    
    Order** orderArray = new Order * [count];
    int index = 0;

    
    currentNode = head;
    while (currentNode != nullptr) {
        if (Cstring_compare1(currentNode->Order_problem, target) == 1) {
            orderArray[index] = currentNode;
            index++;
        }
        currentNode = currentNode->next;
    }

    
    for (int i = 1; i < count; i++) {
        Order* key = orderArray[i];
        int j = i - 1;
        while (j >= 0 && strcmp(orderArray[j]->Order_typeofdevice, key->Order_typeofdevice) < 0) {
            orderArray[j + 1] = orderArray[j];
            j--;
        }
        orderArray[j + 1] = key;
    }

    
    for (int i = 0; i < count; i++) {
        Order* currentOrder = orderArray[i];
        cout << "Order number: " << currentOrder->Order_number << endl;
        cout << "Day of the month: " << currentOrder->Order_dayofmonth << endl;
        cout << "Client's name: " << currentOrder->Order_client << endl;
        cout << "Type of the device: " << currentOrder->Order_typeofdevice << endl;
        cout << "Order id: " << currentOrder->Order_id << endl;
        cout << "Problem: " << currentOrder->Order_problem << endl;
        cout << "Technik's name: " << currentOrder->Order_nameoftechnik << endl;
        cout << "Order status: " << currentOrder->Order_status << endl;
        cout << "-------------------------------------\n";
    }

    
    delete[] orderArray;
}
void Delete_order_by_number(Order** head, unsigned int orderNumber) {
    if (*head == nullptr) {
        cout << "The list is empty. No orders to delete." << endl;
        return;
    }

    Order* currentNode = *head;

    
    while (currentNode != nullptr && currentNode->Order_number != orderNumber) {
        currentNode = currentNode->next;
    }

    if (currentNode == nullptr) {
        cout << "Order with order number " << orderNumber << " not found." << endl;
        return;
    }

    
    if (currentNode == *head) {
        *head = currentNode->next;
        if (*head != nullptr) {
            (*head)->prev = nullptr;
        }
        delete currentNode;
        cout << "Order with order number " << orderNumber << " deleted successfully." << endl;
        return;
    }

   
    if (currentNode->next == nullptr) {
        currentNode->prev->next = nullptr;
        tail = currentNode->prev;
        delete currentNode;
        cout << "Order with order number " << orderNumber << " deleted successfully." << endl;
        return;
    }

    
    currentNode->prev->next = currentNode->next;
    currentNode->next->prev = currentNode->prev;
    delete currentNode;
    cout << "Order with order number " << orderNumber << " deleted successfully." << endl;
}
void Menu(Order* head, Order* tail, int& Number_of_made_orders)
{
    int Option;

    do {
        cout << "*******************************\n";
        cout << "1. Input new order\n";
        cout << "2. Output devices\n";
        cout << "3. Search and output\n";
        cout << "4. Sort the devices\n";
        cout << "5. Order status.\n";
        cout << "6. Search for a specific problem.\n";
        cout << "7. Search by technik\n";
        cout << "8. Delete an order\n";
        cout << "9. Exit\n";
        cout << "*******************************\n";
        cout << "Pick option:";
        while (!(cin >> Option)) {
            cout << "Enter number please.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        system("cls");
        switch (Option) {
        case 1:
            Add_order(head, tail, Number_of_made_orders);
            system("pause");
            system("cls");
            break;
        case 2:
            int option2;
            do {

                cout << "1.Output orders.\n";
                cout << "2.Output orders in decreasing order.\n";
                cout << "3.Go back.\n";
                cout << "-------------------------------------\n";
                cout << "Enter option:";

                while (!(cin >> option2)) {
                    cout << "Enter number between 1-3 please.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                system("cls");
                switch (option2)
                {
                case 1:
                    Display_orders(head);                  
                    system("pause"); system("cls"); break;
                case 2: Bubble_sort_order_by_number_descending(head);
                    system("pause"); system("cls"); break;
                case 3: Menu(head, tail, Number_of_made_orders);
                    break;

                }
            } while (option2 <= 3); break;                     
        case 3:
            int option3;
            do {
                
                cout << "1.Search by the type of the device.\n";
                cout << "2.Search by the status of the order.\n";
                cout << "3.Go back.\n";
                cout << "-------------------------------------\n";
                cout << "Enter option:";

                while (!(cin >> option3)) {
                    cout << "Enter number between 1-3 please.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                system("cls");
                switch (option3)
                {
                case 1: 
                    Search_by_type_of_device_with_bynary_search(head);
                    system("pause"); system("cls"); break;
                case 2:
                    Search_and_display_orders_by_status_with_bynary_search(head);
                    system("pause"); system("cls"); break;
                case 3: 
                    Menu(head,tail,Number_of_made_orders);
                    break;

                }
            } while (option3 <= 3); break;
        case 4:
            Sort_by_date_with_array_10_with_exchange_sort(head);
            system("pause");
            system("cls");
            break;
        case 5:
            Order_status(head, Number_of_made_orders);
            system("pause");
            system("cls");
            break;
        case 6:    
            Collect_and_sort_orders_for_problem_1_with_insertion_sort(head);
            system("pause");
            system("cls");
            break;
        case 7:
            Search_by_technik_and_sort_with_selection_sort(head);
            system("pause");
            system("cls");
            break;
        case 8:
            int number; 
            cout << "Write order you want to delete:";
            cin >> number;
            Delete_order_by_number(&head, number);
            system("pause");
            system("cls");
            break;
        case 9 :
            exit(0); break;
        default:
            cout << "Invalid option\n";
            Menu(head, tail, Number_of_made_orders); 
            break;
        }
    } while (Option != 9);
}


int main()
{
    int Number_of_made_orders = 0;
    Menu(head, tail, Number_of_made_orders);
    system("pause>0");
}

