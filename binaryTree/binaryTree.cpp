#include <iostream>
using namespace std;




// гілка structure

struct node {
    string Data; //данні
    int count = 0;
    node* left; //поінтери на сусідні гілки
    node* right;

};

//дадавання данних
void Add(string aData, node*& anode) {

    //якщо гілки немає

    if (!anode) { //створюємо і додаєм данні
        anode = new node;
        anode->Data = aData;
        anode->left = 0;
        anode->right = 0;
        anode->count = 0;


        return; //інакше звіряємо те шо вносимо
    }

    else if (anode->Data == aData) { //якшо меньше то в ліво
        anode->count++;
        return;
    }
    else if (anode->Data < aData) { //інакше в гілку справа
        Add(aData, anode->right);
    }
    else { //для повтурок
        Add(aData, anode->left);
    }

}




void inorder(node*& root) {
    if (root != NULL) {
        inorder(root->left);
        for (int i = 0; i <= root->count; i++) {
            cout << root->Data << "\n";
        }
        inorder(root->right);

    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n;
    string data;
    node* root = 0;

    cin >> n;
    while (n != 0) {
        cin >> data;
        Add(data, root);
        n--;
    }

    inorder(root);



    return 0;

}