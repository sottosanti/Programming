#include <stdio.h>
#include <curl/curl.h>
#include <stdlib.h>

size_t process_data(char *buffer, size_t itemsize, size_t nitems, void* ignorethis)
{
    size_t bytes = itemsize * nitems;
    int line_number = 1;
    
    printf("New chunk (%zu bytes)\n", bytes);
    printf("%d:\t", line_number);

    for(int i = 0; i < bytes; i++) {
        printf("%c", buffer[i]);

        if(buffer[i] == '\n') {
            line_number++;
            printf("%d:\t", line_number);
        }
    }

    printf("\n\n");
    return bytes;
}

int main(void)
{
   CURL *curl = curl_easy_init();
   
   if(!curl) {
       fprintf(stderr, "init failed\n");
       return EXIT_FAILURE;
   }

    // set options
    curl_easy_setopt(curl, CURLOPT_URL, "https://unioncounty7day.ezlinksgolf.com/index.html#/preSearch");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, process_data);

    // perform out action
    CURLcode result = curl_easy_perform(curl);
    if(result != CURLE_OK) {
        fprintf(stderr, "download problem: %s\n", curl_easy_strerror(result));
    }

   curl_easy_cleanup(curl);
}

/*

{
    "p01":[
        4549,
        4551,
        4545
    ],
    "p02":"08/17/2021",
    "p03":"5:00 AM",
    "p04":"8:00 PM",
    "p05":0,
    "p06":4,
    "p07":false
}

*/