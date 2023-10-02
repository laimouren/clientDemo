#ifndef _TASK_H
#define _TASK_H
#include "protocol.h"
#include <vector>
#include <thread>
#include <functional>
using std::vector;
#define NUM_THREADS 5
vector<thread> threads(NUM_THREADS);
class task
{
public:
    CURL *curl = nullptr;
    protocol *pro = nullptr;
    string url = 0;
    long long fileSize = 0;
    task() {
        curl = curl_easy_init();
    };
    task(protocol* pro) {
        task();
        this->pro = pro;
    };
    task(string url, protocol* pro) {
        task();
        this->pro = pro;
        this->url = url;
    };
    ~task(){
        curl_easy_cleanup(curl);
    };
    long long getFileSize();
    int multiDownload();
};

#endif