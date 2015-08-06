#include "Storage.h"
#include "Date.h"
#include "Meeting.h"
#include "User.h"

using namespace std;

int main(void) {
    Storage *ins = Storage::getInstance();
    User u1("GJN", "123", "gmail", "1235");
    User u2("KCN", "456", "163", "6789");
    ins->createUser(u1);
    ins->createUser(u2);
    Meeting m1("")
}
