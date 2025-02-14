//! Contains all the execution settings.
/**
 * @file problem_settings.h
 * @author Lorenzo Sciandra
 * @brief Not only MACROs for branch-and-bound, but also for testing and debugging.
 * The two MACROs MAX_VERTEX_NUM and HYBRID that are used to set the maximum number of Node in the Graph and to choose the algorithm to use
 * are now in the CMakeLists.txt file, so that they can be changed from the command line.
 * @version 1.0.0
 * @data 2024-05-1
 * @copyright Copyright (c) 2024, license MIT
 *
 * Repo: https://github.com/LorenzoSciandra/GraphConvolutionalBranchandBound
 *
 */


#ifndef BRANCHANDBOUND1TREE_PROBLEM_SETTINGS_H
#define BRANCHANDBOUND1TREE_PROBLEM_SETTINGS_H
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <errno.h>
#include <pthread.h>


//! The maximum number to set the initial value of Problem and SubProblem.
#define INFINITE DBL_MAX


//! The maximum number of Node in the Graph.
//#define MAX_VERTEX_NUM 20//-- no longer in this file, but in the CMakeLists.txt to be able to change it from the command line.


//! The parameter to choose the algorithm to use, 0 for Classic B&B, 1 for Hybrid B&B.
//#define HYBRID 0 //-- no longer in this file, but in the CMakeLists.txt to be able to change it from the command line.


//! 1 if the MST is solved with the Prim algorithm using Fibonacci Heap, 0 if it is solved with the Kruskal algorithm using MFSets.
#define PRIM 1


//! The maximum number of edges in the Graph.
#define MAX_EDGES_NUM (MAX_VERTEX_NUM * (MAX_VERTEX_NUM - 1) / 2)


//! The first upper bound for the problem, see: https://www.semanticscholar.org/paper/Expected-Travel-Among-Random-Points-in-a-Region-Ghosh/4c395ab42054f4312ad24cb500fb8ca6f7ad3a6c
#define GHOSH_UB (sqrt(MAX_VERTEX_NUM) * 1.27f)


//! Used to debug the code, to check if the execution reaches a certain point.
#define TRACE() fprintf(stderr, "%s (%d): %s\n", __FILE__, __LINE__, __func__)


//! The first constant used to compare two SubProblem in the branch and bound algorithm.
/**
 * @brief Two SubProblem are considered equal if their lower bound is within EPSILON of each other.
 * @see branch_and_bound.c::compare_subproblems()
 */
#define EPSILON (GHOSH_UB / 1000)


//! The second constant used to compare two SubProblem in the branch and bound algorithm.
/**
 * @brief If two SubProblem are equal and their lower bound is within EPSILON2 of each other, their probability is compared.
 * @see branch_and_bound.c::compare_subproblems()
 */
#define EPSILON2 (0.1f * EPSILON)


//! The third constant used to compare two SubProblem in the branch and bound algorithm.
/**
 * @brief If two SubProblem are within EPSILON2 (and therefore equal),
 * the one that has a greater probability than the other of at least BETTER_PROB is considered better.
 * @see branch_and_bound.c::compare_subproblems()
 */
#define BETTER_PROB 0.05f


//! The way with generate the children of a SubProblem.
/**
 * @brief If the probability of a SubProblem is greater than PROB_BRANCH, the children are generated
 * by first imposing the constraint that the edge (i, j) is in the solution and then the constraint that it is not.
 * Otherwise, the children are generated by imposing the constraint that the edge (i, j) is not in the solution and then the constraint that it is.
 * @see branch_and_bound.c::branch()
 */
#define PROB_BRANCH 0.5f


//! The maximum time to run the algorithm. Default: 10 minutes.
#define TIME_LIMIT_SECONDS 600


//! The maximum number of dual iterations for the root of the branch and bound tree.
#define NUM_HK_INITIAL_ITERATIONS (((((float) MAX_VERTEX_NUM * MAX_VERTEX_NUM)/50) + 0.5f) + MAX_VERTEX_NUM + 15)


//! The maximum number of dual iterations for nodes of the branch and bound tree that are not the root.
#define NUM_HK_ITERATIONS (((float) MAX_VERTEX_NUM / 4) + 5)


#endif //BRANCHANDBOUND1TREE_PROBLEM_SETTINGS_H
