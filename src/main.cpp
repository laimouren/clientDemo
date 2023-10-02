#include <iostream>
#include <curl/curl.h>
#include "task.h"
#include "protocol.h"
#include "httpProtocol.h"
using namespace std;

int main(int argc, char* argv[]) {
    string url(argv[1]);
    protocol *pro = new httpProtocol();
    cout << "try to download " << url << endl;
    task t(url, pro);
    t.multiDownload();

    if (pro != nullptr) {
        delete pro;
    }
    return 0;
}