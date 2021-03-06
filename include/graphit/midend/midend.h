//
// Created by Yunming Zhang on 2/14/17.
//

#ifndef GRAPHIT_MIDEND_H
#define GRAPHIT_MIDEND_H

#include <graphit/frontend/fir_context.h>
#include <graphit/midend/mir_context.h>
#include <graphit/midend/mir_emitter.h>
#include <graphit/frontend/schedule.h>

namespace graphit {
    /**
     * Generates MIR_Context used for code generation based on user specified schedule
     */
    class Midend {
    public:
        Midend(FIRContext* fir_context) : fir_context_(fir_context) {

        }

        Midend(FIRContext* fir_context, Schedule * schedule)
                : fir_context_(fir_context), schedule_(schedule) {

        }

        int emitMIR(MIRContext * mir_context);

    private:
        // User specified schedule data strcuture
        Schedule* schedule_ = nullptr;
        // Input fir_context generated by the frontend
        FIRContext* fir_context_ = nullptr;
    };
}
#endif //GRAPHIT_MIDEND_H
