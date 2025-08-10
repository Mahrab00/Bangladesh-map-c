// --- Header Files: Amra kichu Standard "Toolbox" include korchi ---
// --- Header Files: We are including some standard "toolboxes" ---
#include <stdio.h>      // For standard input/output functions like printf() and fgets().
                        // Input/Output er kajer jonno, jemon kichu print kora ba user theke input neya.
#include <string.h>     // For string manipulation functions like strcmp() and strcspn().
                        // Text (string) niye kaj korar jonno, jemon duita text compare kora.
#include <stdlib.h>     // For general utilities, here we need strtol() to convert text to a number.
                        // Shadharon kisu kajer jonno, ekhane amra strtol() use korbo text-ke number e convert korte.


// --- The Map-Drawing Function: Amader "Jadukor" function ja map-ta toiri kore ---
// --- The Map-Drawing Function: Our "magical" function that builds the map ---
// This function reads the secret code (the compressed data) and draws the map.
// Ei function-ta "secret code" (compressed data) pore ebong sheta theke map-ta toiri kore.
void generateMapFromCompressedData(const char *compressed_data) {

    // Create a pointer, which is like a bookmark to keep track of where we are in the secret code.
    // Ekti pointer toiri korlam, ja ekta bookmark er moto kaj korbe amader "secret code" er moddhe.
    const char *ptr = compressed_data;
    
    // This is another pointer that will help us find where a number ends in the code.
    // Eta arekti pointer ja amader bolbe "secret code" e ekta number kothay shesh hoyeche.
    char *end_ptr; 

    // This loop continues as long as we haven't reached the end of our secret code string.
    // Ei loop totokhon cholbe jotokhon na amra amader "secret code" er sheshe pouchachi.
    while (*ptr != '\0') {
        
        // This is the clever part: it reads a number from the text (e.g., '19' from "19s").
        // Eta hocche shobcheye chalaki'r ongsho: ei line-ta text theke number-ta pore (jemon "19s" theke '19').
        long count = strtol(ptr, &end_ptr, 10);
        
        // We move our main bookmark past the number we just read.
        // Amra amader main bookmark-take ekhon number-er porer jaygay niye jabo.
        ptr = end_ptr;

        // Now, we check the character right after the number (s, a, or n) to decide what to do.
        // Ekhon, amra number-er porer character-ta (s, a, ba n) check korbo ebong shei onujayi kaj korbo.
        switch (*ptr) {
            case 's': // If the character is 's', it means we need to print spaces.
                      // Jodi character-ta 's' hoy, tar mane amader space print korte hobe.
                for (int i = 0; i < count; i++) {
                    printf(" ");
                }
                break; // Stop here and go to the next part of the loop. // Ekhane theme jao ebong loop er porer kaj shuru koro.
            
            case 'a': // If it's 'a', we print asterisks ('*').
                      // Jodi 'a' thake, tahole amra asterisk ('*') print korbo.
                for (int i = 0; i < count; i++) {
                    printf("*");
                }
                break; // Stop here. // Ekhane theme jao.

            case 'n': // If it's 'n', it means we need a new line (like pressing Enter).
                      // Jodi 'n' thake, tar mane amader notun line e jete hobe (Enter press korar moto).
                for (int i = 0; i < count; i++) {
                    printf("\n");
                }
                break; // Stop here. // Ekhane theme jao.
        }
        
        // Move the bookmark past the character (s, a, or n) to get ready for the next number.
        // Ebar bookmark-take character-er (s, a, ba n) porer ongsho-te niye jai, poroborti number porar jonno.
        ptr++;
    }
}


// --- The Main Function: Program-er shuru eখান theke hoy ---
// --- The Main Function: The program starts here ---
int main() {
    
    // This is the secret code or "blueprint" for our map.
    // C automatically joins adjacent strings, so we can write it on multiple lines to keep it clean.
    // Eta hocche amader map-er "secret code" ba "blueprint".
    // C pashapashi string-guloke nije thekei jora diye dey, tai amra code porishkar rakhar jonno etake onek line e likhte pari.
    const char *compressed_map_data =
        "19s1a1n" "19s4a1n" "19s9a1n" "17s12a6s1a1n" "16s21a1n" "15s23a1n"
        "16s22a1n" "19s19a1n" "21s17a1n" "25s13a1n" "20s2a3s17a1n"
        "20s47a1n" "16s2a1s49a1n" "15s55a1n" "15s54a1n" "15s53a1n" "18s50a1n"
        "23s42a1n" "23s38a1n" "23s35a1n" "21s35a1n" "21s35a9s3a1n" "22s34a9s5a1n"
        "23s34a7s7a1n" "23s34a1s1a4s8a1n" "25s35a3s8a1n" "25s47a1n" "26s47a1n"
        "26s30a1s15a1n" "26s29a3s2a1s13a1n" "26s26a2s1a3s3a1s12a1n"
        "26s25a2s3a7s11a1n" "27s20a4s4a11s10a1n" "27s11a1s6a9s2a8s11a1n"
        "27s10a4s3a10s1a10s10a1n" "28s4a31s11a1n" "28s4a31s11a1n" "29s2a33s10a1n" 
        "28s4a31s11a1n" "63s3a1n" "64s2a1n" "65s2a1n" "66s1a";

    // Create a small box (an array of 50 characters) to store the user's input.
    // Amra ekta chotto box (50 character er array) toiri korlam user er deya input rakhar jonno.
    char countryName[50];

    // Ask the user to enter a country name.
    // User-ke desh er naam enter korte bolchi.
    printf("Enter country name: ");
    
    // Read the text that the user types, including the Enter key press.
    // User ja type korbe sheta porar jonno ei line, eta Enter key-o pore fele.
    fgets(countryName, sizeof(countryName), stdin);
    
    // A little trick: This finds the Enter key press at the end of the input and removes it.
    // Chotto ekta trick: Ei line-ta user-er input er sheshe থাকা Enter key-er chap-take khuje ber kore fele dey.
    countryName[strcspn(countryName, "\n")] = 0;

    // Compare the user's input with the string "Bangladesh". The `strcmp` function returns 0 if they are identical.
    // User-er deya input-er shathe "Bangladesh" text-er tulona korchi. Jodi duita ekdom mile jay, `strcmp` function-ta 0 return korbe.
    if (strcmp(countryName, "Bangladesh") == 0) {
        
        // If they match, print a message and call our magical function to draw the map.
        // Jodi mile jay, tahole ekta message print korbo ebong amader "jadukor" function-take dakbo map-ta ankar jonno.
        printf("\nDisplaying the map of Bangladesh:\n\n");
        generateMapFromCompressedData(compressed_map_data);

    } else {
        
        // If the names don't match, politely tell the user the map isn't available.
        // Jodi naam na mele, tahole nomro-bhabe user-ke bole dibo je oi map-ta nei.
        printf("\nSorry, the map for '%s' is not available.\n", countryName);
    }

    // Tell the operating system that the program finished successfully.
    // Operating system-ke janacchi je program-ta shofol-bhabe shesh hoyeche.
    return 0;
}