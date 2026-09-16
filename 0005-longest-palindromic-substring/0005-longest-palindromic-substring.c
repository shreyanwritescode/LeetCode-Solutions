int expandaroundcenter(char* s, int left, int right, int strLen){
        while(left>=0&&right<strLen&&s[left]==s[right]){
        left--;
        right++;
    }
    return right-left-1;
}
char* longestPalindrome(char* s) {
    int strLen=strlen(s);
    if (strLen<=1){
        char* result=(char*)malloc((strLen+1)*sizeof(char));
        strcpy(result,s);
        return result;
    }
    int start=0;
    int maxlen=0;
    for(int i=0;i<strLen;i++){
        int len1=expandaroundcenter(s,i,i,strLen);
        int len2=expandaroundcenter(s,i,i+1,strLen);
        int len=(len1>len2)?len1:len2;
        if(len>maxlen){
            maxlen=len;
            start=i-(len-1)/2;
        }
    }
    char* result=(char*)malloc((maxlen+1)*sizeof(char));
    strncpy(result,s+start,maxlen);
    result[maxlen]='\0';
    return result;
}