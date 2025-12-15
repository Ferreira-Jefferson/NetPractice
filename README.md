*This project has been created as part of the 42 curriculum by jtertuli.*

# 🌐 NetPractice: TCP/IP Networking Basics

## 📝 Description 

This project is a practical exercise designed to introduce fundamental concepts of computer networking, specifically focusing on the TCP/IP addressing model. The main goal is to successfully configure 10 non-functioning network diagrams (Levels 1 through 10) by correctly setting up IP addresses, subnet masks, and routing tables to enable communication between specified hosts and external networks.

## 🛠️ Instructions 

This section provides details on how to run the training interface, export configurations, and the submission requirements.

### Running the Training Interface

1. **Download and Extract:** Download the project file attached to the project page and extract its contents to your desired folder.  
2. **Execution:** Open the `index.html` file in your web browser.  
3. **Start:** Enter your `intranet login` in the field provided to load your personal configuration and begin the training.  

### Configuration and Export

1. **Goal Completion:** For each level, adjust the unshaded fields (IPs, Masks, Routes) until all communication goals are met (Status: OK - Congratulations !!).  
2. **Exporting Files:** After successfully completing a level, click the **"Get my config"** button.  

### Submission Details

- **File Requirement:** A total of **10 exported configuration files** (one per level) must be submitted.  
- **Location:** All 10 configuration files must be placed at the **root** of your Git repository.  

## 📚 Resources

This section details the networking concepts studied, classic references, and how AI was used during the project.

### Networking Concepts Studied 

- **TCP/IP Addressing:** Understanding the structure of IPv4 addresses.  
- **Subnet Mask:** The binary tool used to divide an IP address into Network and Host portions.  
- **Default Gateway:** The IP address of the router interface that hosts use to send traffic destined for external networks (outside the local subnet).  
- **Routers and Switches:** Understanding the roles of Layer 3 devices (Routers, which connect different networks) and Layer 2 devices (Switches, which connect devices within the same network).  
- **OSI Layers:** Understanding the 7-layer model (Physical, Data Link, Network, Transport, Session, Presentation, Application) and how TCP/IP maps to it.  
- **CIDR (Classless Inter-Domain Routing):** The use of the `/n` notation for prefix length.  
- **VLSM (Variable Length Subnet Masking):** The technique used to create multiple, non-overlapping subnets from a larger address space to prevent IP wastage.  
- **ARP (Address Resolution Protocol):** The protocol used for local communication to map IP addresses to MAC addresses.  
- **Routing Table & LPM (Longest Prefix Match):** The process by which routers select the most specific path for a packet.  

## 📖 Learning Summary: IP Addressing and Routing

### 1. 🌐 The Basics: IP Address

An IP Address (Internet Protocol) is a unique 32-bit identifier used by every device connected to a network.

- **Structure:** The IP is divided into two essential parts:
  - **Network ID:** Identifies which network the device belongs to.
  - **Host ID:** Identifies the specific device within that network.
- **Octets:** The address is split into four 8-bit sections, called Octets (totaling 32 bits).

### 2. ✂️ Subnet Mask and CIDR

The Subnet Mask is essential for separating the Network and Host portions.

- **Mask Format:** A 32-bit sequence where `1`s represent the Network portion (left) and `0`s represent the Host portion (right).
- **CIDR (Classless Inter-Domain Routing):** Simplified notation (`/n`), where `n` is the number of `1` bits in the mask (e.g., `/24`).
- **Calculation:** To find the Network Address, apply the **bitwise AND** operator between the IP and the Mask.

### 3. 🎯 Subnetting (VLSM)

Subnetting is the process of dividing a large network into smaller sub-networks.

- **VLSM (Variable Length Subnet Masking):** Allows different mask sizes, tailoring subnet size to the exact number of required hosts, avoiding IP waste (an improvement over fixed classes A, B, C).
- **Reserved Addresses:** Each subnet always has two unusable addresses for hosts:
  - **Network Address:** The first IP in the range, used as the subnet identifier.
  - **Broadcast Address:** The last IP in the range, used to send data to all hosts in that subnet.

### 4. 🧭 Routing (Path Decision)

A Router is the device that connects different subnets (or networks).

- **Routing Table:** The router uses a table to decide the next step for a packet. Each entry is a rule: `[Destination] => [Next Hop]`.
- **Next Hop:** The IP address of the next router or gateway closer to the final destination.
- **Default Route (`0.0.0.0/0`):** The **last resort rule**. If the destination IP does not match any specific route, the packet is sent to the **Default Gateway** (usually the Internet router).

### 5. 🥇 Longest Prefix Match (LPM)

This is the most important rule when consulting the Routing Table.

- **Principle:** If a packet matches more than one route (e.g., `/24` and `/0`), the router **always chooses the route with the longest prefix** (the mask with the higher `/n`).
- **Function:** Ensures that more specific routes (e.g., a local network) take priority over generic routes (e.g., the default route).

### 6. 🔗 Local vs. External Communication

The mask and the router define whether communication is local or requires routing:

- **Local Communication (Switch/ARP):** If the destination host is in the **same subnet**, the packet is sent directly using the MAC address (Layer 2).
  - *Golden Rule:* All hosts and the router interface in the same segment (connected by the same Switch) **MUST** belong to the same subnet.
- **External Communication (Routing):** If the destination is in a **different subnet**, the host sends the packet to its **Default Gateway** (the router), which takes responsibility for routing it to the outside world.

### References 

- **[OSI Model Explained](https://www.cloudflare.com/learning/ddos/glossary/open-systems-interconnection-model-osi/):** Documentation or tutorials detailing the structure and function of the 7-layer OSI model.  
- **[Guide to Subnetting](https://www.networkfuntimes.com/a-complete-beginners-guide-to-subnetting/):** Documentation or tutorials explaining core networking concepts (e.g., subnetting, routing tables).  
- **[Curso de Endereçamento IP – Canal Hardware Redes Brasil](https://www.youtube.com/playlist?list=PLAp37wMSBouCU49LV0qFbItufigjYk-sp):** Video lessons covering IP addressing fundamentals, subnetting, and practical exercises.  

### AI Usage

AI assistance was utilized for the following tasks:

- **Conceptual Explanations:** Gaining clarity on complex topics like the ARP process, the "No Reverse Way" error, and the logic behind the Longest Prefix Match rule.  
- **Best Practices and Review:** Checking proposed solutions and rules against industry-standard best practices (e.g., correct use of the `/0` default route vs. specific static routes).  
- **Documentation Formatting:** Structuring the `README.md` file according to the specific formatting and content requirements provided in the project guidelines.  
