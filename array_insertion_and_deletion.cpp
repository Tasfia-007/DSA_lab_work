#include <bits/stdc++.h>
using namespace std;

int searchElement(int arr[],int size,int ele)
{
   for (int i = 0; i < size; i++) {
        if (arr[i] == ele) {
            return i;
        }
    }
    return -1;
}

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int insertele(int arr[], int size, int ele, int position) {

    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = ele;

    cout << "element inserted successfully.\n";
    return size+1;
}

int insertBeforeele(int arr[], int size, int serele, int ele)
{
      int index = searchElement(arr,size,serele);
       if (index == -1) {
        cout << "element not found in the array.\n";
        return -1;
    }
       return insertele(arr,size,ele,index);
}

int insertAfterele(int arr[], int size,int serele, int ele) {
    int index = searchElement(arr, size, serele);
     if (index == -1) {
        cout << "element not found in the array.\n";
        return -1;
    }

    for (int i = size; i > index+1; i--) {
        arr[i] = arr[i - 1];
    }

    arr[index+1] = ele;

    cout << "element inserted successfully.\n";

     return size+1;
}



int deleteele(int arr[], int size, int position) {
    if (position < 0 || position >= size) {
        cout << "Invalid position!\n";
        return size-1;
    }

    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    cout << "element deleted successfully.\n";
    return size-1;
}

int main() {
    const int MAX_SIZE = 1000;
    int arr[MAX_SIZE];
    //int size = 0;


    int n;
    cin>>n;
    cout<<"Create the array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }


     int choice, ele, position,serele;

    while (true) {
        cout << "Array Operations:\n";
        cout << "1. Insert ele\n";
        cout << "2. Delete ele\n";
        cout << "3. Display array\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to insert: ";
                cin >> ele;
                cout<<"Insertion by 1.position\n 2.before/after an element\n";
                int c;
                cin>>c;
                if(c==1)
                {
                cout << "Enter the position to insert: ";
                cin >> position;
                n = insertele(arr, n, ele, position);
                }
                else
                {
                    cout<<"1.Insert Before\n 2.Insert After\n";
                    int cc;
                    cin>>cc;
             if(cc==1)
             {
                 cout << "Enter the element to search: ";
                cin >> serele;
                n= insertBeforeele(arr, n, serele, ele);
                     }
                     else
                     {
                 cout << "Enter the element to search: ";
                cin >> serele;
                n = insertAfterele(arr, n, serele, ele);
                   }
                }

                break;
            case 2:
                cout << "Enter the Position/Element to delete:\n";
                cout<<"1.position\n2.element\n";
                int ch;
                cin>>ch;
                if(ch==1)
                {
                cin >> position;
                n = deleteele(arr, n, position);
                }
                else
                {
                    cin>>serele;
                    n = deleteele(arr,n,searchElement(arr,n,serele));
                }
                break;

            case 3:
                cout << "Array elements: ";
                displayArray(arr, n);
                break;
            case 4:
                cout << "Exiting...\n";
                exit(0);
            default:
                cout << "Invalid choice!\n";
        }
        cout << endl;
    }

}
