#include <iostream>

// Function that takes a pointer to an integer and modifies its value
void modifyByPointer(int* ptr) {
    if (ptr != nullptr) { // Always check for nullptr before dereferencing
        *ptr = 100; // Dereference the pointer and modify the value it points to
        std::cout << "Inside modifyByPointer: Value at address " << ptr << " is now " << *ptr << std::endl;
    } else {
        std::cout << "Inside modifyByPointer: Received a nullptr." << std::endl;
    }
}

// Function that takes a reference to an integer and modifies its value
void modifyByReference(int& ref) {
    ref = 200; // Directly modify the variable that ref refers to
    std::cout << "Inside modifyByReference: Value is now " << ref << std::endl;
}

int main() {
    int myValue = 10;
    std::cout << "Original myValue: " << myValue << std::endl;
    std::cout << "Address of myValue: " << &myValue << std::endl; // Get the memory address of myValue

    // --- Pointers ---
    std::cout << "\n--- Demonstrating Pointers ---" << std::endl;
    int* myPointer = nullptr; // Declare a pointer to an int, initialized to nullptr
    myPointer = &myValue;    // Assign the address of myValue to myPointer

    std::cout << "Value of myPointer (address it holds): " << myPointer << std::endl;
    std::cout << "Value pointed to by myPointer (*myPointer): " << *myPointer << std::endl; // Dereference

    // Modify myValue using the pointer
    *myPointer = 50;
    std::cout << "myValue after modifying via pointer: " << myValue << std::endl;
    std::cout << "Value pointed to by myPointer after modification: " << *myPointer << std::endl;

    // Pass a pointer to a function
    modifyByPointer(&myValue); // Pass the address of myValue
    std::cout << "myValue after modifyByPointer call: " << myValue << std::endl;


    // --- References ---
    std::cout << "\n--- Demonstrating References ---" << std::endl;
    int& myReference = myValue; // Declare a reference to myValue
                                // myReference is now an alias for myValue

    std::cout << "Value of myReference: " << myReference << std::endl;
    std::cout << "Address of myReference: " << &myReference << std::endl; // Same as address of myValue

    // Modify myValue using the reference
    myReference = 75;
    std::cout << "myValue after modifying via reference: " << myValue << std::endl;
    std::cout << "Value of myReference after modification: " << myReference << std::endl;

    // Pass a reference to a function
    modifyByReference(myValue); // Pass myValue directly (it's passed by reference)
    std::cout << "myValue after modifyByReference call: " << myValue << std::endl;

    // Demonstrate that a reference cannot be reassigned
    int anotherValue = 300;
    // myReference = anotherValue; // This would assign the VALUE of anotherValue to myValue,
                                // NOT rebind myReference to anotherValue.
                                // myReference still refers to myValue.
    std::cout << "\nAfter attempting to 'reassign' myReference to anotherValue (which assigns value):\n";
    std::cout << "myValue: " << myValue << std::endl; // myValue is now 300
    std::cout << "anotherValue: " << anotherValue << std::endl; // anotherValue is still 300
    std::cout << "myReference: " << myReference << std::endl; // myReference is 300 (because it's myValue)

    // Verify addresses are still the same
    std::cout << "Address of myValue: " << &myValue << std::endl;
    std::cout << "Address of myReference: " << &myReference << std::endl;

    return 0;
}