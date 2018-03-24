// command-line interface (CLI)

class CLI {
        //Obtener = Get
        //Establecer = Set
    public:
        //======== setters y getters ======== 
        char getOpcion();
        void setOpcion ( char opcion );
        //======== funciones de menu ======== 
        void introduccion();
        void acercaDe();
        void ayuda();
        void eleccion();
        void hasElegido();
        void listadOpcionesPricipales();
        //======== subfunciones de menu ======== 
        void menuPrincipal();
		  void menu1Var();
        void menu2Var();
        void menuNVar();
        void menuMatrices();
        void menuMuestreo();
        //void crearDatosMuestra();
        void menuSinDatos();
		  void menuTablasCont();
        //======== funciones especificas de cada submenu ======== 
        void menuInferencia();
        void menuCombinatoria();
        void menuIA();
        void menuDistribDiscreta();
		  //======== Entrada/Salida vectores ========
		  //void iniciarVector();
		  //void numElementosVector();
		  //======== Menús ========
		  void textOpcionesMenu1Var();
    private:
        char opcion;
    };



