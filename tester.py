import subprocess
import os
from colorama import init as init_colorama, Fore
init_colorama()

def compile_cpp_file():
    try:
        subprocess.run(['g++', 'main.cpp', '-o', 'tests/main'], check=True)
        print("Compilation successful.")
    except subprocess.CalledProcessError:
        print("Compilation failed.")

def run_tests():
    try:
        for test_input_file in sorted(os.listdir('tests/input')):
            test_number = test_input_file.split('.')[0]
            test_output_file = f"tests/output/{test_number}.txt"

            with open(f'tests/input/{test_input_file}') as input_file, open(test_output_file) as output_file:
                test_input = input_file.read().strip()
                expected_output = output_file.read().strip()

                process = subprocess.Popen('tests/main', stdin=subprocess.PIPE, stdout=subprocess.PIPE, text=True)
                actual_output, _ = process.communicate(test_input)
                if actual_output.strip() == expected_output.strip():
                    print(Fore.GREEN + f"Test {test_number}: Passed")
                else:
                    print(Fore.RED + f"Test {test_number}: Failed")
                    print("Expected Output:")
                    print(expected_output.strip())
                    print("Actual Output:")
                    print(actual_output.strip())
    except FileNotFoundError:
        print("Input or output files not found.")

if __name__ == "__main__":
    compile_cpp_file()
    run_tests()
