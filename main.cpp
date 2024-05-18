#include "menu.h"
#include "tests.h"

using namespace std;

int main() {

    LinkedList<int> list;
    Array<int> array;
    Test(reinterpret_cast<Sequence<int> *>(&list));
    Test(&array);
    cout << "\nAll tests completed successfully!\n";

    cout << "\n-~~~~==Hello!==~~~~-\n";
    cout << "Press 0 to run Array menu, Press 1 to run LinkedList menu:\n";

    int type;
    cin >> type;

    if (type == 0) {
        ArrayMenu();
    } else if (type == 1) {
        LinkedListMenu();
    } else {
        cout << "\nUnknown command, try again.\n";
    }

    return 0;
}
