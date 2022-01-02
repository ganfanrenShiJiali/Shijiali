//KMP算法
void prefix_table(char needle[],int prefix[],int n)
{
    prefix[0]=0;
    int len=0;
    int i=1;
    while(i<n)
    {
        if(needle[i]==needle[len])
        {
            len++;
            prefix[i]=len;
            i++;
        }
         else
        {
            if(len>0)
                len=prefix[len-1];
            else
            {
                prefix[i]=len;
                i++;
            }
        }
    }
}
void move_prefix_table(int prefix[],int n)
{
    int i;
    for(i=n-1;i>0;i--)
    {
        prefix[i]=prefix[i-1];
    }
    prefix[0]=-1;
}
int strStr(char haystack[], char needle[])
{
    if(strlen(needle)==0) return 0;
    int n=strlen(needle);
    int m=strlen(haystack);
    int* prefix=malloc(sizeof(int)*n);
    prefix_table(needle,prefix,n);
    move_prefix_table(prefix,n);
    int i=0;
    int j=0;
    while(i<m)
    {
        if(j==n-1 && haystack[i]==needle[j])
        {
            return i-j;
        }
        if(haystack[i]==needle[j])
        {
            i++;
            j++;
        }
        else
        {
            j=prefix[j];
            if(j==-1)
            {
                i++;
                j++;
            }
        }
    }
    return -1;
}
