class Solution {
public:
    string entityParser(string text) {
        string str="";
        int k=0;
        for(int i=0;i<text.length();i++)
        {
            if(text[i] == '&')
            {
                if(text.substr(i,3).compare( "&gt") == 0)
                {
                    str +='>';i=i+3;continue;
                }
                if(text.substr(i,3).compare("&lt") == 0)
                {
                    str +='<';i=i+3;continue;
                }
                if(text.substr(i,4).compare( "&amp") == 0)
                {
                    str +='&';i=i+4;continue;
                }
                if(text.substr(i,5).compare("&apos") == 0)
                {
                    str +='\'';
                    i=i+5;continue;
                }
                if(text.substr(i,5).compare("&quot") == 0)
                {
                    str +='"';i=i+5;continue;
                }
                if(text.substr(i,6).compare("&frasl") == 0)
                {
                    str +='/';i=i+6;continue;
                }       
                str +=text[i];
            }
            else
            {
                str +=text[i];continue;
            }
                
        }
        return str;
        
    }
};