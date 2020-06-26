#include <visual/visual.h>
#include <algorithms/Graph.h>
#include <gvc.h>


Visual::Visual(Graph *g1, std::string nn)
{
    char* argv[3];
    int argc;

    Agraph_t *g;

    GVC_t *gvc;

    /* set up a graphviz context */
    gvc = gvContext();

    nn="-o "+nn+".svg";


    char* s=strdup(nn.c_str());


    /* parse command line args - minimally argv[0] sets layout engine */
    argv[0]="dot";
    argv[1]="-Tsvg";
    argv[2]=s;
    argc=3;
    gvParseArgs(gvc, argc, argv);

    /* Create a simple digraph */
    g = agopen("g",Agundirected, 0);//Agundirected  Agdirected


    for (int v = 0; v < g1->size(); v=++v)
    {
        list<int>  arr= g1->get_adj(v);

        //printf("\n Adjacency list of vertex %d\n head ", v);
        for(unsigned int i=0;i<=arr.size();++i)
        {
            char nm[5];
            Agnode_t *n1,*n2;
            Agedge_t *e;
            sprintf(nm,"%d",v);
            n1 = agnode(g, nm , 1);
            sprintf(nm,"%d",arr.front());
            arr.pop_front();

            n2 = agnode(g, nm, 1);
            e = agedge(g, n1, n2, 0, 2);

            agsafeset(n1, "color", "red", "sd");
            agsafeset(e, "dim", "16", "sd");
            agsafeset(e, "margin", " 0.51,0.095", "sd");

        }

    }



    /* Set an attribute - in this case one that affects the visible rendering */
    /* Compute a layout using layout engine from command line args */
    gvLayoutJobs(gvc, g);
    /* Write the graph according to -T and -o options */
    gvRenderJobs(gvc, g);
    /* Free layout data */
    gvFreeLayout(gvc, g);
    /* Free graph structures */
    agclose(g);

    /* close output file, free context, and return number of errors */
    gvFreeContext(gvc) ;


}
