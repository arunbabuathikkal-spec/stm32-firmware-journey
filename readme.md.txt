Phase 2: Automotive Protocols, Diagnostics & Real-Time OS (Weeks 13–20)
Goal: Master the communication standards and diagnostic frameworks used in 95%+ of modern Electronic Control Units (ECUs).
Week 13: Advanced CAN & CAN FD (Flexible Data-Rate)
•	Objective: Upgrade standard CAN drivers to support high-throughput CAN FD.
•	Key Concepts: Bit-Rate Switching (BRS), Nominal vs. Data Phase Bit Timing, Payload expansion (up to 64 bytes), CRC polynomials.
•	Hands-on Exercise: Write driver code to configure the MCU for a 500 kbps arbitration phase and a 2 Mbps or 5 Mbps data phase using an external CAN FD transceiver (e.g., MCP2518FD or onboard CAN FD controller).
Week 14: Local Interconnect Network (LIN Bus)
•	Objective: Implement sub-system master/slave networking for body electronics (doors, mirrors, seats).
•	Key Concepts: LIN Header (Break Field, Sync Byte 0x55, Protected Identifier - PID), Response Payload, Enhanced Checksum.
•	Hands-on Exercise: Configure a USART peripheral in LIN Mode to act as a LIN Master node that sends frame headers and parses slave responses.
Week 15: Transport Protocol (ISO-TP / ISO 15765-2)
•	Objective: Implement the network layer engine capable of segmenting and reassembling diagnostic messages up to 4095 bytes over CAN.
•	Key Concepts: Frame types: Single Frame (SF), First Frame (FF), Consecutive Frame (CF), and Flow Control (FC) frame timing (STmin, BS).
•	Hands-on Exercise: Build an ISO-TP state machine that receives a multi-frame buffer, handles Flow Control negotiation, and emits a reassembled payload buffer.
Week 16: Unified Diagnostic Services (UDS / ISO 14229)
•	Objective: Implement standard ECU diagnostic services required for vehicle calibration and dealer service tools.
•	Key Concepts:
o	$10 Diagnostic Session Control (Default, Extended, Programming).
o	$22 / $2E Read / Write Data By Identifier (DID).
o	$19 Read DTC (Diagnostic Trouble Codes) & Fault Management.
•	Hands-on Exercise: Build a UDS handler that processes $22 to return dynamic sensor values and $10 to switch diagnostic sessions.
Week 17: UDS Security Access & Flash Bootloaders
•	Objective: Implement secure memory flashing protocols for ECU firmware updating.
•	Key Concepts:
o	$27 Security Access (Seed & Key validation algorithm).
o	$34 / $36 / $37 Request Download, Transfer Data, Exit Transfer.
o	Internal Flash Memory Erase/Program drivers & Dual-Bank Bootloading.
•	Hands-on Exercise: Write a minimal bare-metal bootloader residing in Flash Sector 0 that validates a cryptographic key, receives an S-Record/HEX payload over ISO-TP, and flashes it to Application Memory.
Week 18: Automotive Ethernet & DoIP (ISO 13400)
•	Objective: Interface high-speed ECU diagnostics over IP-based physical layers.
•	Key Concepts: 100BASE-T1 physical layer fundamentals, TCP/IP stack integration (LwIP), DoIP header structure, Routing Activation Requests.
•	Hands-on Exercise: Configure an Ethernet MAC/PHY to parse DoIP diagnostic requests over TCP port 13400 and route them to your UDS service layer.
Week 19: OSEK/VDX & RTOS Scheduling Paradigms
•	Objective: Transition from basic FreeRTOS to automotive-standard real-time operating concepts (OSEK / AUTOSAR OS).
•	Key Concepts: Static task assignment, Priority Ceiling Protocol (preventing priority inversion), Alarm/Event triggers, OIL (OSEK Implementation Language) files.
•	Hands-on Exercise: Configure an open-source OSEK-compliant OS (like Trampoline or FreeOSEK) to schedule periodic 10ms, 50ms, and 100ms task loops with deterministic execution windows.
Week 20: Network Management (NM) & ECU Power Modes
•	Objective: Manage low-power state transitions across vehicle networks.
•	Key Concepts: OSEK/AUTOSAR Network Management state machines (Bus-Sleep, Prepare Bus-Sleep, Network Mode), Partial Networking, CAN Wakeup Interruption.
•	Hands-on Exercise: Implement an NM state machine that monitors network activity and triggers MCU Stop/Sleep mode when no keep-alive tokens are detected.
Phase 3: AUTOSAR Classic Architecture & Model-Based Design (Weeks 21–28)
Goal: Learn the standard software architecture required by major automakers to separate application logic from hardware.
+-----------------------------------------------------------------------+
|                 Application Layer (SWCs / Runnable Entities)          |
+-----------------------------------------------------------------------+
|                     RTE (Run-Time Environment)                        |
+-----------------------------------------------------------------------+
|   Services Layer  |  ECU Abstraction Layer | Microcontroller Abstraction  |
| (Diagnostic/NM/OS)|    (IoHwAb / CanIf)    |       (MCAL Drivers)       |
+-----------------------------------------------------------------------+
Week 21: AUTOSAR Classic Overview & MCAL Configuration
•	Key Concepts: 3-Layer Architecture (Application, RTE, BSW), Microcontroller Abstraction Layer (MCAL).
•	Hands-on Exercise: Use open-source or evaluation tools (e.g., OpenSAR, ArcCore/Embedded System Environment, or Vector DaVinci Developer trial) to map hardware pins using standard Port, Dio, Gpt, and Can MCAL modules.
Week 22: ECU Abstraction & Basic Software (BSW) Stack
•	Key Concepts: CanIf (CAN Interface), CanTp (CAN Transport), PduR (PDU Router), Com module.
•	Hands-on Exercise: Configure the PDU Router to pass raw CAN signals up from CanIf through Com into structured signal buffers.
Week 23: Run-Time Environment (RTE) & SWCs
•	Key Concepts: Software Components (SWCs), Ports & Interfaces (Sender-Receiver, Client-Server), Runnable Entities, RTE contract headers.
•	Hands-on Exercise: Write an Application SWC in C containing a Runnable function that reads a signal from an RTE port (Rte_Read_*) and drives an RTE output port (Rte_Write_*).
Weeks 24–25: Diagnostic Stack Integration (Dem, Det, Dcm)
•	Key Concepts:
o	Dcm (Diagnostic Communication Manager) — Handles UDS framing.
o	Dem (Diagnostic Event Manager) — Stores Fault Memory & Freeze Frames.
o	Det (Development Error Tracer) — Catches runtime API misuse.
•	Hands-on Exercise: Route a software fault event from an Application SWC to the Dem module to set a Diagnostic Trouble Code (DTC) in simulated non-volatile memory (NvM).
Weeks 26–28: Model-Based Design (MBD) with MATLAB / Simulink
•	Objective: Master the toolchain used by control algorithms engineers (powertrain, ADAS, chassis).
•	Key Concepts: Stateflow logic diagrams, discrete-time controller modeling, Fixed-Point arithmetic, Embedded Coder code generation.
•	Hands-on Exercise:
1.	Build a Simulink control loop (e.g., Adaptive Cruise Control or Motor Speed Governor).
2.	Perform Software-in-the-Loop (SIL) testing.
3.	Generate C code using Embedded Coder configured with AUTOSAR target settings, generating ready-to-use SWC source code.
Phase 4: Functional Safety (ISO 26262), Security & Verification (Weeks 29–34)
Goal: Ensure your software meets safety-critical standards, passes static analysis, and can be integrated into production lines.
Weeks 29–30: ISO 26262 Functional Safety Execution
•	Key Concepts:
o	Automotive Safety Integrity Levels (ASIL A through ASIL D).
o	Hazard Analysis and Risk Assessment (HARA).
o	Safety Mechanisms: Lockstep Cores, RAM Pattern Tests (MARCH-C), Clock Monitoring, External Window Watchdogs.
•	Hands-on Exercise: Implement an ASIL-D safety mechanism: Write a driver that services an external SPI-based Window Watchdog (e.g., TPS65381/SBC) with a dynamic challenge-response token loop.
Week 31: Embedded Cybersecurity (ISO/SAE 21434 & HSM)
•	Key Concepts: Hardware Security Modules (HSM), Secure Boot validation chains, Message Authentication Codes (CAN-SecOC / Secure On-Board Communication).
•	Hands-on Exercise: Implement a SecOC payload verifier that checks an incoming AES-128 CMAC tag on a CAN message before accepting it into your control logic.
Weeks 32–33: Static Analysis & Automated Testing (MISRA & Unit Testing)
•	Key Concepts: MISRA C:2012 / AUTOSAR C++14 compliance, Structural Code Coverage (Statement, Branch, MC/DC Coverage).
•	Hands-on Exercise:
1.	Run static analysis tools (Cppcheck, SonarQube, or PC-Lint) on your repository and eliminate 100% of high-severity MISRA violations.
2.	Set up GoogleTest or Unity unit tests for your ISO-TP/UDS stack to achieve 100% Statement and Branch Coverage.
Week 34: CI/CD Pipeline & Portfolio Finalization
•	Key Concepts: Automated build systems (CMake / Ninja), GitHub Actions / Jenkins integration, Hardware-in-the-Loop (HIL) automation setups.
•	Hands-on Exercise: Configure a GitHub Actions pipeline that runs static analysis, builds your firmware using arm-none-eabi-gcc, and runs unit test suites automatically on every git commit.

