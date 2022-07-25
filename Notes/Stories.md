# Arm Stories

## Design Reducer

* C++
* Create reproducer of large error when compiling large RTL design
    * Arm's IP are large, complex, varied by team. Hard to pinpoint error when compiler failure
    * Reduce design while keeping error
    * Implement removal of design features
    * Greater reduction in design while maintaining error; Used to debug internal and customer errors

*Invent and Simplify*
*Deliver Results*

## CM Config

* Python
* Integration of C++ models
    * Incredibly hard to integrate - libraries, headers, source code, definitions, etc.
    * Needed to simplify integration and create a common interface
    * Developed python tool that fetches build data from meta-data generated w/ each model
    * Integrated into all models, used by all our systems & external partners

*Invent and Simplify*
*Earn Trust*
*Have Backbone; Disagree and Commit*
*Deliver Results*

## IPX

* Javascript
* New web-based portal for Cycle Models
    * Existing web based portal was obsolete (old machines, old framework, insecure)
    * Build new web-portal; learn Javascript, react, redux, database management
    * Re-wrote & abstracted database management so easier to understand; wrote input sanitization for security; cleaned up and wrote frontend state managmenet
    * Working web portal; no issues with database management; and no issues w/ pen testing

*Invent and Simplify*
*Are Right a Lot*
*Insist on the Highest Standards*
*Deep Dive*
*Deliver Results*

## Analytics Integration

* C++
* Add analytics to Cycle Models
    * Product manager request & department initiative; Add analytics to cycle models
    * Review, breakdown, plan requirement; Add analytics into compiler, runtime, and models
    * High impact runtime first first; Resolve significant issues with library dependencies; Updated tool requirements
    * Analytics released, most people turned them off; I was the head contact for anything analytics related

*Ownership*
*Earn Trust*
*Deep Dive*

## YAMF-Based Model Deliveries

* CMake, Build Systems
* Delivered one-off models for customers while assembling a quick and dirty build system
    * Customers, internal and external, wanted models of IP we didn't have in flows
    * My team was tasked with providing those models; Could not fit into existing flows
    * Took half-baked CMake-based flow + finished getting build steps working; Added test/release infrastructure
    * Able to release one-off models 4x faster than before; Quick turnaround for customers while more productized flow was built

*Customer Obsession*
*Invent and Simplify*
*Deliver Results*

## RTL Co-Simulation Project - Leadership

* C++; Leadership
* Enable co-simulation in RTL simulators
    * Wrapped in SystemC crashes with RTL sims; Second flavor with limitted features + confusion
    * Recognized pain points; Wanted to add support for full CM product
    * Sketched out intern project; Led interns through implementation
    * 2/3 simulators supported & documented; Handed to other team after they left

*Customer Obsession*
*Are Right a Lot*
*Learn and Be Curious*
*Think Big*

## Marvin ML System (?)
## CMN 600 + Hercules System (?)

## Arm Custom Datapath Extension & SystemC Scheduler

* C++ / SystemC
* Debugged scheduler issues with Arm CDE solution
    * Arm added CDE support to some IP; Wanted to support it in Cycle Models
    * Design solution & resolve issues
    * Determined how to extract internal pins; Encountered scheduling issues; Pin-pointed exact issues with scheduling; Ramped team up on SystemC and scheduling issues
    * Plan sketched out for supporting CDE; Team working on new scheduler

*Customer Obsession*
*Learn and Be Curious*
*Deep Dive*

## CPAK Improvements

* Python
* Re-architected, organized, and simplified repository and build flow
    * Started producing 'systems' more; Used an older repo of primarily scripting (Bash & Python);
    * Clean up the repo; make it easy use, update, understand
    * Split up classes, separated responsibilities; added out of source build/test; test release packages; ripped out dead code; break downstreem dependencies; Add system configurations
    * Much easier to use repo; Much more managemable systems; Supported our system development needs

*Ownership*
*Invent and Simplify*
*Insist on the Highest Standards*

## ML Systems in IPSS (PoC)

* Javasript; C++
* Added Cycle Model versions of ML systems into IP Selection Sandbox
    * Downloadable PoC product for compare/contrast IP; ML team wanted their IP showcased
    * Build Cycle Model system to match functional one; Run their software; Integreate with IPSS
    * Built models of components; Stitched them together; Analyzed & rebuilt/stitched based on FPGA system; Re-designed how we post-process software to load into memories; Integreated with IPSS
    * System releasd into IPSS; Now being migreated to productized version

*Learn and Be Curious*
*Bias for Action*

## Productize IPSS Systems - Leadership

* C++; Leadership
* Productize Cycle Model systems for IPSS and support more IP
    * IPSS got green light for productization; Needed to support existing system + many new ones
    * Productize systems; Integrate them with soon-to-come backend
    * Stepped into Leadership role; Refined requirements; Established communication channels & structure; Defined interfaces for un-realized backend solution; Built flows and new systems to our specs; Integrated with backend
    * 32 systems delivered into backend on time; Release is now public;

*Ownership*
*Are Right a Lot*
*Think Big*
*Have Backbone; Disagree and Commit*
*Deliver Results*

## Custom Applications in IPSS Systems 

* C++, C
* Support Custom Applications in IPSS systems
    * Marketing / Product wanted customers to upload/run custom software
    * Enable workflow for custom software on all systems
    * Hardware Abstraction Layer + Benchmark; Defined interface between HAL + Benchmark; Resolved compatibility checking and release scenarios
    * Custom software supported and public to customers

*Customer Obsession*
*Invent and Simplify*
*Think Big*

## RTL IPSS System Design - Leadership

* Design
* Design the RTL development & delivery 'system'
    * Transition to RTL systems; Efficiently develop, produce, test, release RTL systems
    * Work w/ team leads to design high level architecture, what happens where; what are interface
    * Interacted in meetings - talking in circles; Drafted architecture; Refined with other tech leads; Provided input around applications and system interfaces
    * All tech & team leads on same page; work broken down; under development

*Learn and Be Curious*
*Insist on the Highest Standards*
*Think Big*
*Have Backbone; Disagree and Commit*

## Application Development for RTL Systems - Leadership

* Bazel; Leadership
* Development of Hardware Abstraction Layer packages for RTL systems
    * Intern joining my team; Needed work that was valuable, new, and familiar to the team;
    * Outline work required for HAL packages in RTL systems; Flush out details enough for intern
    * Created stories; Reviewed with other tech leads + team; Ramped up intern and guided him
    * One story left in the epic; Whole team was involved; Much farther along than expected

*Bias for Action*
*Earn Trust*
*Deliver Results*

## ML Systems in Productized IPSS

* Python
* Port ML Systems to Productized IPSS 
    * ML team descoped; Line of buisiness wants at least partial support
    * Determine feasability + costs; Flush out requirements; Outline work
    * Wrote wrappers for ML systems; Built up infrastructure to package and test; Communicated interface + presentation changes to frontend
    * Systems released and integrated with backend; Management aware of & accepts the limitations

*Invent and Simplify*
*Deliver Results*
