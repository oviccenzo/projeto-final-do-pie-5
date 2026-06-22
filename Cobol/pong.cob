       IDENTIFICATION DIVISION.
       PROGRAM-ID. GAME.

       DATA DIVISION.
      
       WORKING-STORAGE SECTION.

       01 AS-RUNNING       PIC 9(1).

       PROCEDURE DIVISION.

           CALL STATIC "init_game" USING AS-RUNNING
           PERFORM UNTIL AS-RUNNING = 0
               CALL STATIC "update_game" USING AS-RUNNING
           END-PERFORM
           CALL STATIC "quit_game"

           STOP RUN.
