# Desenho de Algoritmos (DA) - Year 2, Semester 2 (Y2S2)

This repository contains all the exercises and assessments of the UC Desenho de Algoritmos, taught by [Rosaldo Rossetti](https://sigarra.up.pt/feup/pt/func_geral.formview?p_codigo=419241) and [Ana Paula Tomás](https://www.dcc.fc.up.pt/~apt/) at [Integrated Master in Informatics and Computing Engineering](https://sigarra.up.pt/feup/pt/cur_geral.cur_view?pv_curso_id=742) [MIEIC] at the [Faculty of Engineering of the University of Porto](https://sigarra.up.pt/feup/pt/web_page.Inicial) [FEUP]. <br> <br>

<h2 align = "center" >Final Grade: __ /20</h2>
<p align = "center" >
  <img 
       title = "FEUP logo"
       src = "Images//FEUP_Logo.png" 
       alt = "FEUP Logo" 
       />
</p>

## Here are several documents, namely:

### My Drafts <br/>
Pieces of code for exercises and assessments, notes that I take during practical classes and other experiences using C and C++ languages. It is an authentic disorganized notebook. <br>

### Notes
Notes that I take during theoretical lectures, in Cpp files or Markdown <br>

### Exercises
Varied exercises of easy, medium and difficult level, about the subject taught in the present week. They complement the weekly work developed during the practical classes. <br>

### Project 1 - Urban Logistics for Packages Delivery (Grade: 18.5/20)

A delivery company wants to see its business maximized according to the following scenarios:

- Optimization of the number of couriers;
- Optimization of the company's profit bgity delivering orders using lower cost vans;
- Optimization of express deliveries, improving average delivery time;

The following project implements solutions for each of the cases using some studied algorithms, such as greedy, bin-packing, knapsack and job scheduling. <br>
The original repository can be viewed [here](https://github.com/marcwferreira/DA_estafetas).

#### Empirical evaluation

In addition to the C++ language, we also use Python and Bash to assess the complexity of the algorithms. We built a script ([packagesGenerator.py](https://github.com/Fabio-A-Sa/Y2S2-DesenhoDeAlgoritmos/blob/f3c95ae412b0470d87595489dab075c960c00c6b/Project%201/codigo/AvaliacaoEmpirica/packagesGenerator.py)) that generates N orders based on the original data provided by the teachers, ensuring that a percentage are express orders. Then the project script is called via a Bash script, which injects the orders file and the necessary parameters into a `caseX.sh`, returning the time in seconds of each execution to the `output.csv` file. The cycle is repeated 10 times in increments of 2000 units for each case. The advantage of `.csv` is that it can be interpreted by Excel and that's where we were able to build a graph, with regression lines to evaluate the linearity of each case.

#### With:

- [x] Francisco João Gonçalves Calado Araújo
- [x] Fábio Araújo de Sá
- [x] Marcos William Ferreira Pinto

### Project 2 - Logistics for Travel Organization (Grade: 19.3/20)

A travel agency wants to organize routes and connections for its customers in the best possible way. For this you need different features:

1. Groups without separation:
  - Maximization of the number of elements of the group to be transported;
  - Minimization of the number of transfers of the trip;

2. Split groups:
  - Determine a referral for a group;
  - Change an existing route if the group size increases;
  - Determine the maximum size of a group and a forwarding;
  - Determining when the full group would meet again at the destination;
  - Determine the maximum waiting time that group members can wait at intermediate stops;

The following project implements solutions for each of the cases using some studied algorithms. The original repository can be viewed [here](https://github.com/marcwferreira/FEUP_DA_travel_agency).

#### Empirical evaluation

In addition to the C++ language, we also use Python and Bash to assess the complexity of the algorithms. We built a script ([graphGenerator.py](https://github.com/Fabio-A-Sa/Y2S2-DesenhoDeAlgoritmos/blob/main/Project%202/codigo/AvaliaçãoEmp%C3%ADrica/graphGenerator.py)) that generates a DAG graph with N nodes and N * FACTOR edges, which are based on the original data provided by the teachers, ensuring time and cost bounds. Then the project script is called via a Bash script, which injects the orders file and the necessary parameters into a `timer.sh`, returning the time in seconds of each execution to the `output.csv` file. For some cases we vary the number of nodes (and consequently the size of the graph) with increments of 1000 for 10 cycles. In other cases, we vary the number of people traveling and the necessary paths with increments of 10 for 10 cicles. The advantage of `.csv` is that it can be interpreted by Excel and that's where we were able to build a graph, with regression lines to evaluate the linearity of each case.

#### Testing



#### With:

- [x] Fábio Araújo de Sá
- [x] Marcos William Ferreira Pinto

**@ Fábio Araújo de Sá** <br>
**2021/2022**