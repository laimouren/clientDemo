#include "task.h"
long long task::getFileSize() {
    if (url.empty()) {
        cout << "url is empty, get file size failed" << endl;
        return 0;
    }
    /* 设置option */
    curl_easy_setopt(curl, CURLOPT_URL, url);
    CURLcode code = curl_easy_perform(curl);
    if (code == CURLE_OK) {
        long long fileSize = 0;
        code = curl_easy_getinfo(curl, CURLINFO_CONTENT_LENGTH_DOWNLOAD, &fileSize);
        if (code == CURLE_OK) {
            cout << "get file " << url << " size: " << fileSize << endl;
            return fileSize;
        }
        
    }
    cout << "get " << url << " file size failed" << endl;
    return 0;
}
int task::multiDownload() {
    if (url.empty()) {
        cout << "url is empty, download failed" << endl;
        return -1;
    }
    /* 设置option */
    curl_easy_setopt(curl, CURLOPT_URL, url);
    this->fileSize = getFileSize();
    
    long long part = this->fileSize / NUM_THREADS;
    int begin = 0, end = part - 1;
    
    for (int i = 0; i < NUM_THREADS; ++i) {
        /* 将成员函数绑定到func对象，因为成员函数不能直接赋值给函数指针 */
        threads[i] = thread(std::bind(&protocol::download, pro, this->curl, this->url, begin, end));
        begin += part;
        end += (i = NUM_THREADS - 1) ? this->fileSize - 1 : end + part - 1;
    }
    
    for (auto& thread : threads) {
        thread.join();
    }

    std::cout << "Download completed." << std::endl;

    return 0;
}