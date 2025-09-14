#include <iostream>
#include <string>
#include <random>

// Function to generate a random password
std::string generate_password(int length) {
    const std::string lowercase_letters = "abcdefghijklmnopqrstuvwxyz";
    const std::string uppercase_letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string digits = "0123456789";
    const std::string symbols = "!@#$%^&*()_+-=[]{}|;:,.<>?";

    const std::string all_characters = lowercase_letters + uppercase_letters + digits + symbols;

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(0, all_characters.length() - 1);

    std::string password;
    password.reserve(length);

    for (int i = 0; i < length; ++i) {
        password += all_characters[distribution(generator)];
    }

    return password;
}

int main() {
    int password_length;
    std::cout << "Enter the desired password length (e.g., 12): ";
    std::cin >> password_length;

    if (std::cin.fail() || password_length <= 0) {
        std::cout << "Invalid input. Please enter a positive number." << std::endl;
        return 1;
    }

    std::string new_password = generate_password(password_length);
    std::cout << "Your new password is: " << new_password << std::endl;

    return 0;
}