//Выполнили: Чекунова Марьяна, Ванина Дарья, Анашкин Илья БПМ-22-2

#include <iostream>
#include <vector>
#include <list>
#include <stack>

void sequentialRepresentation() { //Функция смежного представления конечной последовательности
    int size;
    std::cout << "Введите размер последовательности: ";
    std::cin >> size;

    std::vector<int> sequence;

    std::cout << "Введите элементы последовательности:\n";
    //добавление элементов в последовательность
    for (int i = 0; i < size; i++) {
        int a;
        std::cin >> a;
        sequence.push_back(a);
    }
    // Вывод содержимого последовательности
    std::cout << "Содержимое последовательности (смежное представление):\n";
    for (int i = 0; i < sequence.size(); i++) {
        std::cout << sequence[i] << " ";
    }
    std::cout << std::endl;

    bool addMore = true;
    std::cout << "Хотите ли вы добавить элементы? (1 - да, 0 - нет): ";
    std::cin >> addMore;
    while (addMore) {
        //добавление элемента
        int element;
        std::cout << "Введите элемент для добавления: ";
        std::cin >> element;
        sequence.push_back(element);

        std::cout << "Хотите ли вы добавить еще элементы? (1 - да, 0 - нет): ";
        std::cin >> addMore;
    }

    std::cout << "Содержимое последовательности (смежное представление):\n";
    for (int i = 0; i < sequence.size(); i++) {
        std::cout << sequence[i] << " ";
    }
    std::cout << std::endl;

    bool removeMore = true;
    std::cout << "Хотите ли вы удалить последний элемент? (1 - да, 0 - нет): ";
    std::cin >> removeMore;
    while (removeMore && !sequence.empty()) {
        // Удаление последнего элемента и его вывод
        std::cout << "Удаляем последний элемент: " << sequence.back() << std::endl;
        sequence.pop_back();

        std::cout << "Хотите ли вы удалить еще элементы? (1 - да, 0 - нет): ";
        std::cin >> removeMore;
    }

    std::cout << "Содержимое последовательности (смежное представление):\n";
    for (int i = 0; i < sequence.size(); i++) {
        std::cout << sequence[i] << " ";
    }
} 

void linkedRepresentation() { //Функция связного представления конечной последовательности
    int size;
    std::cout << "Введите размер последовательности: ";
    std::cin >> size;

    std::list<int> sequence;

    std::cout << "Введите элементы последовательности:\n";
    // Заполнение последовательности с помощью ввода пользователем
    for (int i = 0; i < size; i++) {
        int element;
        std::cin >> element;
        sequence.push_back(element);
    }

    std::cout << "Содержимое последовательности (связное представление):\n";
    // Вывод содержимого последовательности
    for (const auto& element : sequence) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    bool addMore = true;
    std::cout << "Хотите ли вы добавить элементы? (1 - да, 0 - нет): ";
    std::cin >> addMore;
    while (addMore) {
        //добавление элемента
        int element;
        std::cout << "Введите элемент для добавления: ";
        std::cin >> element;
        sequence.push_back(element);

        std::cout << "Хотите ли вы добавить еще элементы? (1 - да, 0 - нет): ";
        std::cin >> addMore;
    }

    std::cout << "Содержимое последовательности (связное представление):\n";
    for (const auto& element : sequence) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    bool removeMore = true;
    std::cout << "Хотите ли вы удалить последний элемент? (1 - да, 0 - нет): ";
    std::cin >> removeMore;
    while (removeMore && !sequence.empty()) {
        // Удаление последнего элемента и его вывод
        std::cout << "Удаляем последний элемент: " << sequence.back() << std::endl;
        sequence.pop_back();

        std::cout << "Хотите ли вы удалить еще элементы? (1 - да, 0 - нет): ";
        std::cin >> removeMore;
    }

    std::cout << "Содержимое последовательности (связное представление):\n";
    for (const auto& element : sequence) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
} 

void arrayRepresentation() { //Функция смежного представления массива
    int size;
    std::cout << "Введите размер массива: ";
    std::cin >> size;

    int* array = new int[size];

    std::cout << "Введите элементы массива:\n";
    // Заполнение массива с помощью ввода пользователем
    for (int i = 0; i < size; i++) {
        std::cin >> array[i];
    }

    std::cout << "Содержимое массива (смежное представление):\n";
    // Вывод содержимого массива
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    bool addMore = true;
    std::cout << "Хотите ли вы добавить элементы? (1 - да, 0 - нет): ";
    std::cin >> addMore;
    while (addMore) {
        int element;
        std::cout << "Введите элемент для добавления: ";
        std::cin >> element;

        // Увеличение размера массива и создание нового массива с добавленным элементом
        size++;
        int* newArray = new int[size];
        for (int i = 0; i < size - 1; i++) {
            newArray[i] = array[i];
        }
        newArray[size - 1] = element;

        // Освобождение памяти от старого массива, замена на новый массив
        delete[] array;
        array = newArray;

        std::cout << "Хотите ли вы добавить еще элементы? (1 - да, 0 - нет): ";
        std::cin >> addMore;
    }

    std::cout << "Содержимое массива (смежное представление):\n";
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    bool removeMore = true;
    std::cout << "Хотите ли вы удалить последний элемент? (1 - да, 0 - нет): ";
    std::cin >> removeMore;
    while (removeMore && size > 0) {
        // Удаление последнего элемента и его вывод
        std::cout << "Удаляем последний элемент: " << array[size - 1] << std::endl;

        // Уменьшение размера массива и создание нового массива без последнего элемента
        size--;
        int* newArray = new int[size];
        for (int i = 0; i < size; i++) {

            newArray[i] = array[i];
        }

        // Освобождение памяти от старого массива, замена на новый массив
        delete[] array;
        array = newArray;

        std::cout << "Хотите ли вы удалить еще элементы? (1 - да, 0 - нет): ";
        std::cin >> removeMore;
    }
    std::cout << "Содержимое массива (смежное представление):\n";
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    delete[] array;
} 

void linkedArrayRepresentation() { //Функция связного представления массива
    int size;
    std::cout << "Введите размер массива: ";
    std::cin >> size;

    std::list<int> linkedArray;

    std::cout << "Введите элементы массива:\n";
    //заполняем массив
    for (int i = 0; i < size; i++) {
        int element;
        std::cin >> element;
        linkedArray.push_back(element);
    }

    std::cout << "Содержимое массива (связное представление):\n";
    //выводим элементы связного массива
    for (const auto& element : linkedArray) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    bool addMore = true;
    std::cout << "Хотите ли вы добавить элементы? (1 - да, 0 - нет): ";
    std::cin >> addMore;
    while (addMore) {
        //цикл для добавления дополнительных элементов в связный массив
        int element;
        std::cout << "Введите элемент для добавления: ";
        std::cin >> element;
        linkedArray.push_back(element);

        std::cout << "Хотите ли вы добавить еще элементы? (1 - да, 0 - нет): ";
        std::cin >> addMore;
    }

    std::cout << "Содержимое массива (связное представление):\n";
    for (const auto& element : linkedArray) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    bool removeMore = true;
    std::cout << "Хотите ли вы удалить последний элемент? (1 - да, 0 - нет): ";
    std::cin >> removeMore;
    while (removeMore && !linkedArray.empty()) {
        //цикл для удаления последнего элемента из связного массива
        std::cout << "Удаляем последний элемент: " << linkedArray.back() << std::endl;
        linkedArray.pop_back();

        std::cout << "Хотите ли вы удалить еще элементы? (1 - да, 0 - нет): ";
        std::cin >> removeMore;
    }

    std::cout << "Содержимое массива (связное представление):\n";
    for (const auto& element : linkedArray) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
} 

struct TreeNode { // Структура для представления узла дерева
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int _data) : data(_data), left(nullptr), right(nullptr) {}
};

TreeNode* insertNode(TreeNode* root, int data) { // Вставка нового узла в дерево
    if (root == nullptr) {
        return new TreeNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else {
        root->right = insertNode(root->right, data);
    }

    return root;
}
// Обход дерева в порядке "in-order" 
// (сначала левое поддерево, затем текущий узел, затем правое поддерево)
void inOrderTraversal(TreeNode* root) { 
    if (root == nullptr) {
        return;
    }

    inOrderTraversal(root->left);
    std::cout << root->data << " ";
    inOrderTraversal(root->right);
}

TreeNode* deleteNode(TreeNode* root, int data) { // Удаление узла из дерева
    if (root == nullptr) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    else {
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        TreeNode* minNode = root->right;
        while (minNode->left != nullptr) {
            minNode = minNode->left;
        }

        root->data = minNode->data;
        root->right = deleteNode(root->right, minNode->data);
    }

    return root;
}

void treeRepresentation() { // Функция для смежного представления дерева
    TreeNode* root = nullptr;

    int size;
    std::cout << "Введите размер дерева: ";
    std::cin >> size;

    std::cout << "Введите элементы дерева (в порядке поиска):\n";
    for (int i = 0; i < size; i++) { // заполняем дерево
        int element;
        std::cin >> element;

        root = insertNode(root, element);
    }

    std::cout << "Содержимое дерева (смежное представление):\n";
    // вызываем функцию для обхода дерева в порядке "in-order" и выводим содержимое
    inOrderTraversal(root);
    std::cout << std::endl;

    bool addMore = true;
    std::cout << "Хотите ли вы добавить элементы? (1 - да, 0 - нет): ";
    std::cin >> addMore;
    while (addMore) {
        // цикл для добавления элементов в дерево
        int element;
        std::cout << "Введите элемент для добавления: ";
        std::cin >> element;

        root = insertNode(root, element);

        std::cout << "Хотите ли вы добавить еще элементы? (1 - да, 0 - нет): ";
        std::cin >> addMore;
    }

    std::cout << "Содержимое дерева (смежное представление):\n";
    inOrderTraversal(root);
    std::cout << std::endl;

    bool removeMore = true;
    std::cout << "Хотите ли вы удалить элемент? (1 - да, 0 - нет): ";
    std::cin >> removeMore;
    while (removeMore && root != nullptr) {
        // цикл для удаления элементов из дерева
        int element;
        std::cout << "Введите элемент для удаления: ";
        std::cin >> element;

        root = deleteNode(root, element);

        std::cout << "Хотите ли вы удалить еще элементы? (1 - да, 0 - нет): ";
        std::cin >> removeMore;

    std::cout << "Содержимое дерева (смежное представление):\n";
    inOrderTraversal(root);
    std::cout << std::endl;
    } 
}

class BinaryTree {
private:
    struct TreeN {
        int value;
        TreeN* left;
        TreeN* right;
        TreeN(int value) : value(value), left(nullptr), right(nullptr) {}
    }; // Внутренняя структура узла дерева

    TreeN* root;

    void _inorder_traversal(TreeN* node) {
        if (node != nullptr) {
            _inorder_traversal(node->left);
            std::cout << node->value << " ";
            _inorder_traversal(node->right);
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    void add_element(int value) {
        TreeN* new_node = new TreeN(value); // создаем новый узел с заданным значением

        if (root == nullptr) {
            root = new_node;
        }
        else {
            TreeN* current = root;
            while (true) {
                if (value < current->value) {
                    if (current->left == nullptr) {
                        current->left = new_node;
                        break;
                    }
                    else {
                        current = current->left;
                    }
                }
                else {
                    if (current->right == nullptr) {
                        current->right = new_node;
                        break;
                    }
                    else {
                        current = current->right;
                    }
                }
            }
        }

        std::cout << "Элемент " << value << " успешно добавлен." << std::endl;
    }

    bool delete_element(int value) { //удаление елемента
        if (root == nullptr) {
            std::cout << "Дерево пусто. Невозможно удалить элемент." << std::endl;
            return false;
        }

        TreeN* current = root;
        TreeN* parent = nullptr;

        while (current != nullptr && current->value != value) {
            parent = current;
            if (value < current->value) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }

        if (current == nullptr) {
            std::cout << "Элемент " << value << " не найден. Невозможно удалить." << std::endl;
            return false;
        }

        if (current->left == nullptr && current->right == nullptr) {
            if (current == root) {
                root = nullptr;
            }
            else if (current == parent->left) {
                parent->left = nullptr;
            }
            else {
                parent->right = nullptr;
            }

            delete current;
        }
        else if (current->left != nullptr && current->right != nullptr) {
            TreeN* successor = current->right;
            TreeN* successor_parent = nullptr;

            while (successor->left != nullptr) {
                successor_parent = successor;
                successor = successor->left;
            }

            current->value = successor->value;

            if (successor_parent != nullptr) {
                successor_parent->left = successor->right;
            }
            else {
                current->right = successor->right;
            }

            delete successor;
        }
        else {
            TreeN* child = (current->left != nullptr) ? current->left : current->right;

            if (current == root) {
                root = child;
            }
            else if (current == parent->left) {
                parent->left = child;
            }
            else {
                parent->right = child;
            }

            delete current;
        }

        std::cout << "Элемент " << value << " был удалён." << std::endl;
        return true;
    }

    void show() { //вывод содержимого
        if (root == nullptr) {

            std::cout << "Дерево пусто." << std::endl;
        }
        else {
            std::cout << "Связное дерево: ";
            _inorder_traversal(root);
            std::cout << std::endl;
        }
    }
};

void binaryTreeOperations() { // Функция для связного представления дерева
    BinaryTree tree;

    int elementsCount;
    std::cout << "Введите количество элементов в дереве: ";
    std::cin >> elementsCount;

    std::cout << "Введите элементы дерева:" << std::endl;
    for (int i = 0; i < elementsCount; i++) {
        int element;
        std::cin >> element;
        tree.add_element(element);
    }

    tree.show();

    bool addMore = true;
    std::cout << "Хотите ли добавить элементы? (1 - да, 0 - нет): ";
    std::cin >> addMore; // Добавляем элемент в дерево
    while (addMore) {
        int element;
        std::cout << "Введите элемент для добавления: ";
        std::cin >> element;
        tree.add_element(element);

        std::cout << "Хотите ли добавить еще элементы? (1 - да, 0 - нет): ";
        std::cin >> addMore;
    }

    tree.show();

    bool removeMore = true;
    std::cout << "Хотите ли удалить элемент? (1 - да, 0 - нет): ";
    std::cin >> removeMore;
    while (removeMore) { //удаляем елемент
        int element;
        std::cout << "Введите элемент для удаления: ";
        std::cin >> element;

        tree.delete_element(element);

        std::cout << "Хотите ли удалить еще элементы? (1 - да, 0 - нет): ";
        std::cin >> removeMore;
    }

    tree.show(); //вывод содержимого
}

int main() {
    setlocale(LC_ALL, "Russian");
    int choice;
    std::cout << "Выберите представление:\n"
        << "1. Смежное представление(конечная последовательность)\n"
        << "2. Связное представление(конечная последовательность)\n"
        << "3. Смежное представление(одномерный массив)\n"
        << "4. Связное представление(одномерный массив)\n"
        << "5. Смежное представление(дерево)\n"
        << "6. Связное представление(дерево)\n"
        << "Выберите опцию: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
        sequentialRepresentation();
        break;
    case 2:
        linkedRepresentation();
        break;
    case 3:
        arrayRepresentation();
        break;
    case 4:
        linkedArrayRepresentation();
        break;
    case 5:
        treeRepresentation();
        break;
    case 6:
        binaryTreeOperations();
        break;
    default:
        std::cout << "Некорректный выбор." << std::endl;
        break;
    }

    return 0;
}
