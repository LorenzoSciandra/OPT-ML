/**
 * @file main.c
 * @author Lorenzo Sciandra
 * @brief Project main file, where you start the program, read the input file and print/write the results.
 * @version 1.0.0
 * @data 2024-05-1
 * @copyright Copyright (c) 2024, license MIT
 *
 * Repo: https://github.com/LorenzoSciandra/GraphConvolutionalBranchandBound
 *
 */


#include "../test/main_test.h"


/**
 * @brief Main function, where you start the program, read the input file and print/write the results.
 * @param argc The number of arguments passed to the program.
 * @param argv The arguments passed to the program.
 * @return 0 if the program ends correctly, 1 otherwise.
 */
int main(int argc, char *argv[]) {

    if (argc != 3) {
        perror("Wrong number of arguments");
        printf("\nYou need to pass 2 arguments: <input file> <output file>\n");
        exit(1);
    }


    char *input_file = argv[1];
    char *output_file = argv[2];

    //printf("\nNodes:%d \t\tMode: %s\t\t\n", MAX_VERTEX_NUM, HYBRID ? "Hybrid" : "Classic");

    //printf("\nReading from file '%s'\n", input_file);
    //printf("\nWriting to file '%s'\n", output_file);

    freopen(output_file, "w+", stdout);

    //run_all_tests();

    static Problem new_problem;

    //read_tsp_lib_file(&new_problem.graph, input_file);
    read_tsp_csv_file(&new_problem.graph, input_file);

    //print_graph(&new_problem.graph);

    branch_and_bound(&new_problem);

    print_problem();

    fclose(stdout);

    return 0;
}
