# NetworkProtocolSmulation
This repository contains a collection of C programs developed for the Computer Networks course at the University of Piraeus. The projects focus on network performance evaluation, end-to-end delay calculations, packet fragmentation, and the implementation of classic routing algorithms.

## Technologies
* **Language:** C
* **Core Concepts:** Network Routing, Graph Algorithms, Network Performance Modeling, Edge Computing.

## Projects Overview

### 1. Edge vs. Cloud Server Delay Analysis (`1st_Project.c`)
Evaluates whether it is more efficient to process a packet on an Edge node or a Cloud Server. 
* Calculates the processing time for both scenarios based on bit rate, packet size, and processing delays.
* Computes the maximum number of nodes ($K_{max}$) for which processing on the Server remains optimal.

### 2. End-to-End Network Delay Calculator (`2nd Project.c`)
Calculates the total communication delay between two network nodes.
* Takes into account **Transmission**, **Propagation**, **Queuing**, and **Processing** delays.
* Calculates the total bits transmitted up to a specific user-defined time ($t_1$).

### 3. Network Packet Fragmentation Simulator (`3rd Project.c`)
Analyzes the impact of packet fragmentation on network delay across multiple hops.
* Calculates the total delay **without** fragmentation.
* Calculates the total delay **with** fragmentation based on a given fragment size ($F$) and header size ($H$).
* Computes the arrival time of the first fragment at the destination.

### 4. Link-State & Distance Vector Routing (`4.1 Project.c`)
A network routing simulator that implements two classic shortest-path algorithms for a 6-node network topology.
* **Dijkstra's Algorithm** (Link-State)
* **Bellman-Ford Algorithm** (Distance Vector)
* Calculates link costs dynamically based on Bit Rate and Packet Size, and outputs the optimal routing tables and shortest paths for given source nodes.

### 5. Optimal Path Selection (`4.2 Project.c`)
A decision algorithm that calculates and compares the total delay of two different network paths (e.g., via a Wi-Fi Access Point vs. a Base Station) to find the fastest route.

## ⚙️ How to Compile and Run
You can compile any of the C files using the GCC compiler. For example:
```bash
gcc "4.1 Project.c" -o routing_algo
./routing_algo
