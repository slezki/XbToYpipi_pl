# XbToYpipi_pl

This Proof-Lite package has been created to be run on multicore machines for high statistic X<sub>b</sub> to Y(1S)π<sup>+</sup>π<sup>-</sup> analysis!

* Setup:

```
git clone git@github.com:slezki/XbToYpipi_pl.git
```

* Check number of available workers:


![available workers](https://github.com/slezki/pics/blob/ca3d2b58c517b2ab23e8a3cc7521fb646f9844c8/CheckWorkersForProofLite.png)

Here number of __workers__ means the number of __cores__ of the machine!
The machine has 40 cores but only 37 cores are available to run on!

In Run.pL_XXX.C, you can set __maximum__ 37 workers:
__TProof *p = TProof::Open("workers=37");__


* Run:

```
root -l Run.pL_XXX.C
```
If you don't need files which are outputs of the Proof-Lite compiler, use:
```
./runRoot.sh XXX
```

For more detail check the [tutorial](https://www.dropbox.com/s/p8io44ocpuhweux/pompili_bari_prooflite_final_static.pdf?dl=0).
