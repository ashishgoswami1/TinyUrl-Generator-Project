#include "url_shortener.h"

URLShortener::URLShortener() {
    characters = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    id = 0;
}

std::string URLShortener::encode(int num) {
    std::string shortURL = "";
    while (num) {
        shortURL += characters[num % 62];
        num /= 62;
    }
    while (shortURL.length() < 6)
        shortURL += '0';
    return shortURL;
}

int URLShortener::decode(const std::string& shortURL) {
    int num = 0;
    for (char c : shortURL) {
        if ('0' <= c && c <= '9') num = num * 62 + c - '0';
        else if ('a' <= c && c <= 'z') num = num * 62 + c - 'a' + 10;
        else if ('A' <= c && c <= 'Z') num = num * 62 + c - 'A' + 36;
    }
    return num;
}

std::string URLShortener::shortenURL(const std::string& longURL) {
    if (longToShort.find(longURL) != longToShort.end())
        return longToShort[longURL];
    
    std::string shortURL = encode(id);
    longToShort[longURL] = shortURL;
    shortToLong[shortURL] = longURL;
    id++;
    return shortURL;
}

std::string URLShortener::expandURL(const std::string& shortURL) {
    if (shortToLong.find(shortURL) != shortToLong.end())
        return shortToLong[shortURL];
    return "Not Found";
}
