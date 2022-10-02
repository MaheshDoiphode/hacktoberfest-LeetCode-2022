import java.io.*;
 
class CountVowel {

    public static void main(String[] args) throws IOException {
        String str = "This is a test string";
        str = str.toLowerCase();
        System.out.println("Total number of vowels in string are: ");
        System.out.println(vowelno(str, str.length()));
    }

    static int isVowel(char chars) {
        if (chars == 'a' || chars == 'e' || chars == 'i' || chars == 'o' || chars == 'u') {
            return 1;
        } else {
            return 0;
        }
    }
 
    static int vowelno(String str, int l) {
        if (l == 1) {
            return isVowel(str.charAt(l - 1));
        }
        return vowelno(str, l - 1) + isVowel(str.charAt(l - 1));
    } 
}