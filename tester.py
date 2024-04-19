import subprocess
import os
import time
from colorama import init as init_colorama, Fore
init_colorama()

def compile_cpp_file():
    try:
        subprocess.run(['g++', 'main.cpp', '-o', 'tests/main', '-std=c++17'], check=True)
        print("Compilation successful.")
    except subprocess.CalledProcessError:
        print("Compilation failed.")
        exit()

def run_tests():
    try:
        for test_input_file in sorted(os.listdir('tests/input')):
            test_number = test_input_file.split('.')[0]
            test_output_file = f"tests/output/{test_number}.txt"

            with open(f'tests/input/{test_input_file}') as input_file, open(test_output_file) as output_file:
                test_input = input_file.read().strip()
                expected_output = output_file.read().strip()

                start_time = time.time() * 1000
                process = subprocess.Popen('tests/main', stdin=subprocess.PIPE, stdout=subprocess.PIPE, text=True)
                end_time = time.time() * 1000
                exec_time = end_time - start_time

                actual_output, _ = process.communicate(test_input)
                print(Fore.RESET + "-")
                if actual_output.strip() == expected_output.strip():
                    print(Fore.GREEN + f"Test {test_number}: Passed in {exec_time:.5f} ms")
                else:
                    print(Fore.RED + f"Test {test_number}: Failed in {exec_time:5.f} ms")
                    print("Expected Output:")
                    print(expected_output.strip())
                    print("Actual Output:")
                    print(actual_output.strip())
    except FileNotFoundError:
        print(Fore.RED + "Input or output files not found.")

if __name__ == "__main__":
    compile_cpp_file()
    run_tests()
