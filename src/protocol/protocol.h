#ifndef _PROTOCOL_H
#define _PROTOCOL_H
#include <string>
#include <iostream>
#include <curl/curl.h>
using namespace std;
class protocol
{
public:
    protocol(){};
    virtual ~protocol(){};
    virtual int download(CURL *curl, string url, long long begin, long long end);
};

int protocol::download(CURL *curl, string url, long long begin, long long end) {
    if (url.empty()) {
        cout << "url is empty, download failed";
        return -1;
    }
    cout << "begin download, url: " << url << ", begin: " << begin << ", end: " << end << endl;
    curl_easy_setopt(curl, CURLOPT_RANGE, to_string(begin) + "_" + to_string(end));
    /* 下载 */
    curl_easy_perform(curl);
    
    cout << "download " << url << " [" << begin << " , " << end << "] success" << endl;
    return 0;
}

#endif