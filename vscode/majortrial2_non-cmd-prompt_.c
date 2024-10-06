#include <windows.h>
#include <stdio.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 100
#define MAX_FILENAME_LENGTH 150

// Global variables
char user_name[MAX_USERNAME_LENGTH];
int PIN, balance;
char file_name[MAX_FILENAME_LENGTH];
HINSTANCE hInst;

// Function prototypes
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);
void createAccount(HWND hwnd);
void login(HWND hwnd);
void transactionMenu(HWND hwnd);
void updateAccount();
void showMessage(HWND hwnd, const char* message);

// Entry point of the application
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    hInst = hInstance;
    MSG msg;
    WNDCLASS wc = { 0 };
    wc.lpszClassName = "BankApp";
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpfnWndProc = WindowProcedure;

    RegisterClass(&wc);
    HWND hwnd = CreateWindow("BankApp", "Bank Application", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        100, 100, 400, 300, NULL, NULL, hInstance, NULL);

    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}

// Window procedure to handle messages
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
        case WM_CREATE:
            createAccount(hwnd); // Start by creating an account
            break;

        case WM_COMMAND:
            if (LOWORD(wp) == 1) { // Yes button for existing account
                login(hwnd);
            }
            else if (LOWORD(wp) == 2) { // No button for new account
                createAccount(hwnd);
            }
            else if (LOWORD(wp) == 3) { // Button to handle transactions
                transactionMenu(hwnd);
            }
            else if (LOWORD(wp) == 4) { // Exit button
                PostQuitMessage(0);
            }
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hwnd, msg, wp, lp);
    }
    return 0;
}

// Function to display messages in a message box
void showMessage(HWND hwnd, const char* message) {
    MessageBox(hwnd, message, "Information", MB_OK | MB_ICONINFORMATION);
}

// Function to create a new account
void createAccount(HWND hwnd) {
    char buffer[MAX_USERNAME_LENGTH];
    int pin;

    // Get the desired username
    sprintf(buffer, "Enter your desired username:");
    showMessage(hwnd, buffer);
    // Create an input dialog box for username
    GetDlgItemText(hwnd, 1, user_name, MAX_USERNAME_LENGTH);
    
    // Create the file name based on the username
    sprintf(file_name, "C:\\BANK_local_storage\\%s.txt", user_name);
    FILE* file = fopen(file_name, "w");

    if (file == NULL) {
        showMessage(hwnd, "An error has occurred. Perhaps someone already used your username? Try something else.");
        return;
    }

    // Get the desired PIN
    sprintf(buffer, "Enter your desired six-digit PIN:");
    showMessage(hwnd, buffer);
    // Create an input dialog box for PIN
    GetDlgItemText(hwnd, 1, buffer, MAX_USERNAME_LENGTH);
    sscanf(buffer, "%d", &pin);

    balance = 1000000;
    fprintf(file, "balance: %d\n", balance);
    fprintf(file, "PIN: %d\n", pin);
    fclose(file);

    showMessage(hwnd, "An account has been created.");
}

// Function to log in an existing account
void login(HWND hwnd) {
    sprintf(file_name, "C:\\BANK_local_storage\\%s.txt", user_name);
    FILE* file = fopen(file_name, "r");

    if (file == NULL) {
        showMessage(hwnd, "Looks like you don't actually have an account.");
        return;
    }

    fscanf(file, "balance: %d\n", &balance);
    fscanf(file, "PIN: %d\n", &PIN);
    
    char buffer[10];
    sprintf(buffer, "Enter your 6-digit PIN:");
    showMessage(hwnd, buffer);
    // Create an input dialog box for PIN
    GetDlgItemText(hwnd, 1, buffer, 10);
    int user_given_pin;
    sscanf(buffer, "%d", &user_given_pin);

    if (user_given_pin != PIN) {
        showMessage(hwnd, "The pin you've typed is incorrect. Please try again.");
        fclose(file);
        return;
    }

    showMessage(hwnd, "You are logged in now.");
    sprintf(buffer, "Your current balance is: %d", balance);
    showMessage(hwnd, buffer);
    fclose(file);
}

// Function to handle transactions
void transactionMenu(HWND hwnd) {
    char buffer[10];
    sprintf(buffer, "Would you like to withdraw, credit or transfer money?\n1 for withdraw\n2 for credit\n3 for transfer");
    showMessage(hwnd, buffer);
    
    // Create input dialog for transaction choice
    GetDlgItemText(hwnd, 1, buffer, 10);
    int choice;
    sscanf(buffer, "%d", &choice);

    FILE* file = fopen(file_name, "r+");
    if (file == NULL) {
        showMessage(hwnd, "Error opening account file.");
        return;
    }

    fscanf(file, "balance: %d\n", &balance);

    int amount;
    switch (choice) {
        case 1: // Withdraw
            sprintf(buffer, "Your current balance is: %d\nPlease enter the amount you would like to withdraw:", balance);
            showMessage(hwnd, buffer);
            // Create input dialog for withdrawal amount
            GetDlgItemText(hwnd, 1, buffer, 10);
            sscanf(buffer, "%d", &amount);

            if (amount > balance) {
                showMessage(hwnd, "You're too broke for this.");
                break;
            } else {
                balance -= amount;
                sprintf(buffer, "You have successfully withdrawn %d. Your new balance is: %d", amount, balance);
                showMessage(hwnd, buffer);
            }
            break;

        case 2: // Credit
            sprintf(buffer, "Please enter the amount you would like to credit:");
            showMessage(hwnd, buffer);
            // Create input dialog for credit amount
            GetDlgItemText(hwnd, 1, buffer, 10);
            sscanf(buffer, "%d", &amount);
            balance += amount;
            sprintf(buffer, "You have successfully credited %d. Your new balance is: %d", amount, balance);
            showMessage(hwnd, buffer);
            break;

        case 3: // Transfer
            showMessage(hwnd, "This feature is under development.");
            break;

        default:
            showMessage(hwnd, "Invalid choice.");
            break;
    }

    rewind(file);
    fprintf(file, "balance: %d\n", balance);
    fprintf(file, "PIN: %d\n", PIN);
    fclose(file);
}
