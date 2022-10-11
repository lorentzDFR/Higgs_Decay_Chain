# Higgs_Decay_Chain
The goal of this project was to use the Composite pattern to generate the following decay chains for the Higgs boson.
<p align="center">
<img src="https://user-images.githubusercontent.com/82932496/195068830-6ff97a5e-068a-4007-9d86-54ff40d474fc.png" width="400" >

**Particle** is characterised by its mass, three vector of its momentum, electric charge, an integer id number and a name, while **Composite Particle** has a list of children. 

I generated 10000 Higgs decays to two photons with the Higgs momentum in the laboratory reference frame, where the momentum is sampled from  a Gaussian distribution of mean 50 GeV and width of 10%. Here are shown the plots of the distribution of the opening angle between the two photons, and the distributions of momenta for the children of the two Z bosons. I used ROOT libraries for random generation and plotting.
<p align="center">
<img src="https://user-images.githubusercontent.com/82932496/195070773-c95b6cc1-6aa8-403d-be54-17ee5789141e.png" width="450" >
<img src="https://user-images.githubusercontent.com/82932496/195070767-466f1c11-cfbc-4a49-9395-7ea909dc5982.png" width="650" >

